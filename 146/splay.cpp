#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Splay;
struct Node;

struct Splay {
  int key_;
  Node *node_;
};

struct SplayStore {
  size_t root_ = 0;
  std::vector<Splay> stores_ = {{}}; // dummy node
  std::vector<size_t> parents_ = {{}};
  std::vector<std::vector<size_t>> children_ = {{}};

  void update(size_t idx) {
    // nop
  }

  void rotate(size_t idx) {
    auto parent = parents_[idx];
    auto grandparent = parents_[parent];

    size_t son_idx = children_[parent][1] == idx;
    children_[parent][son_idx] = children_[idx][son_idx ^ 1];
    parents_[children_[idx][son_idx ^ 1]] = parent;
    parents_[idx] = parents_[parent];
    parents_[parent] = idx;
    children_[idx][son_idx ^ 1] = parent;
    if (grandparent) children_[grandparent][parent == children_[grandparent][1]] = idx;

    update(parent);
    update(idx);
  }

  void splay(size_t idx) {
    size_t parent = 0;
    while (parent = parents_[idx]) {
      auto grandparent = parents_[parent];
      if (grandparent) {
        size_t idx_of_parent_in_son = parent == children_[grandparent][1];
        size_t idx_of_son_in_son = idx == children_[parent][1];
        if (idx_of_parent_in_son ^ idx_of_son_in_son) {
          rotate(idx);
        } else {
          rotate(parent);
        }
      }
      rotate(idx);
    }
    root_ = idx;
  }

  size_t insert(int key) {
    if (!root_) {
      root_ = stores_.size();
      stores_.emplace_back().key_ = key;
      parents_.emplace_back(0);
      children_.emplace_back();
      children_.back().push_back(0);
      children_.back().push_back(0);

      return root_;
    }

    size_t idx = root_, parent = 0;
    while (idx) {
      // assume no same key
      parent = idx;
      idx = children_[idx][key > stores_[idx].key_];
    }

    size_t son_idx = key > stores_[parent].key_;
    idx = stores_.size();

    children_[parent][son_idx] = idx;
    stores_.emplace_back().key_ = key;
    parents_.push_back(parent);
    children_.emplace_back();
    children_.back().push_back(0);
    children_.back().push_back(0);

    splay(idx);
    return idx;
  }

  size_t search(int key) {
    if (!root_) return 0;
    auto idx = root_;
    while (idx) {
      if (stores_[idx].key_ == key) {
        splay(idx);
        return idx;
      }
      if (stores_[idx].key_ > key) idx = children_[idx][0];
      else idx = children_[idx][1];
    }
    return idx;
  }

  void combine(size_t left, size_t right) {
    while (children_[left][1]) left = children_[left][1];
    splay(left);
    children_[left][1] = right;
    parents_[right] = left;

    update(left);
  }

  void clear(size_t idx) {
    stores_[idx].key_ = 0;
    stores_[idx].node_ = nullptr;
    parents_[idx] = children_[idx][0] = children_[idx][1] = 0;
  }

  void del(size_t idx) {
    splay(idx);
    for (auto child: children_[idx])
      parents_[child] = 0;
    if (!children_[idx][0] && !children_[idx][1]) {
      clear(idx);
      root_ = 0;
      return;
    }
    for (int i = 0; i < 2; ++i) {
      if (!children_[idx][i]) {
        root_ = children_[idx][i ^ 1];
        clear(idx);
        return;
      }
    }

    combine(children_[idx][0], children_[idx][1]);
  }
};

struct Node {
  size_t idx_;
  int val_;
  Node *prev_;
  Node *next_;
};

class LRUCache {
 public:
  SplayStore store_;
  size_t capacity_;
  size_t size_ = 0;
  Node *dummy_;

  LRUCache(int capacity) {
    capacity_ = capacity;
    dummy_ = new Node;
    dummy_->prev_ = dummy_->next_ = dummy_;
  }

  void put(int key, int val) {
    auto node = store_.search(key);
    if (!node) {
      node = store_.insert(key);
      if (size_ < capacity_) {
        auto new_node = new Node;
        new_node->val_ = val;
        new_node->idx_ = node;
        store_.stores_[node].node_ = new_node;
        dummy_->next_->prev_ = new_node;
        new_node->next_ = dummy_->next_;
        dummy_->next_ = new_node;
        new_node->prev_ = dummy_;
        ++size_;
      } else {
        auto old_node = dummy_->prev_;
        store_.del(old_node->idx_);
        store_.stores_[node].node_ = old_node;
        old_node->next_->prev_ = old_node->prev_;
        old_node->prev_->next_ = old_node->next_;
        dummy_->next_->prev_ = old_node;
        old_node->next_ = dummy_->next_;
        dummy_->next_ = old_node;
        old_node->prev_ = dummy_;

        old_node->val_ = val;
        old_node->idx_ = node;
      }
    } else {
      auto old_node = store_.stores_[node].node_;

      old_node->next_->prev_ = old_node->prev_;
      old_node->prev_->next_ = old_node->next_;
      dummy_->next_->prev_ = old_node;
      old_node->next_ = dummy_->next_;
      dummy_->next_ = old_node;
      old_node->prev_ = dummy_;
      old_node->val_ = val;
    }
  }

  int get(int key) {
    auto node = store_.search(key);
    if (!node) return -1;

    auto old_node = store_.stores_[node].node_;

    old_node->next_->prev_ = old_node->prev_;
    old_node->prev_->next_ = old_node->next_;
    dummy_->next_->prev_ = old_node;
    old_node->next_ = dummy_->next_;
    dummy_->next_ = old_node;
    old_node->prev_ = dummy_;

    return old_node->val_;
  }
};


int main() {
  auto cache = new LRUCache(3);

  std::vector<std::string> ops = {"put", "put", "put", "put", "get", "get", "get", "get", "put", "get", "get", "get",
                                  "get",
                                  "get"};
  std::vector<std::vector<int>> params = {{1, 1},
                                          {2, 2},
                                          {3, 3},
                                          {4, 4},
                                          {4},
                                          {3},
                                          {2},
                                          {1},
                                          {5, 5},
                                          {1},
                                          {2},
                                          {3},
                                          {4},
                                          {5}};

  for (int i = 0; i < ops.size(); ++i) {
    auto &param = params[i];
    if (ops[i] == "put") {
      cache->put(param[0], param[1]);
    } else {
      std::cout << cache->get(param[0]) << ' ' << std::endl;
    }
  }
  return 0;
}
