
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
static const RamDomain RAM_BIT_SHIFT_MASK = RAM_DOMAIN_SIZE - 1;
struct t_btree_iii__0_1_2__100__111 {
using t_tuple = Tuple<RamDomain, 3>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :(0)));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> lowerUpperRange_100(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_100(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_100(lower,upper,h);
}
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_111(lower,upper,h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 3 direct b-tree index 0 lex-order [0,1,2]\n";
ind_0.printStats(o);
}
};
struct t_btree_ii__0_1__11__10 {
using t_tuple = Tuple<RamDomain, 2>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_11(lower,upper,h);
}
range<t_ind_0::iterator> lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_10(lower,upper,h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 2 direct b-tree index 0 lex-order [0,1]\n";
ind_0.printStats(o);
}
};
struct t_btree_i__0__1 {
using t_tuple = Tuple<RamDomain, 1>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :(0);
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[1];
std::copy(ramDomain, ramDomain + 1, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0) {
RamDomain data[1] = {a0};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_0(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> lowerUpperRange_0(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> lowerUpperRange_1(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_1(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_1(lower,upper,h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 1 direct b-tree index 0 lex-order [0]\n";
ind_0.printStats(o);
}
};
struct t_btree_iii__0_1_2__111 {
using t_tuple = Tuple<RamDomain, 3>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :(0)));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_111(lower,upper,h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 3 direct b-tree index 0 lex-order [0,1,2]\n";
ind_0.printStats(o);
}
};
struct t_btree_iii__1_2_0__011__111 {
using t_tuple = Tuple<RamDomain, 3>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :((ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :(0)));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))|| (ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2])) && ((ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]))&&(ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> lowerUpperRange_011(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_011(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_011(lower,upper,h);
}
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_111(lower,upper,h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 3 direct b-tree index 0 lex-order [1,2,0]\n";
ind_0.printStats(o);
}
};
struct t_btree_iiii__0_1_2_3__1111 {
using t_tuple = Tuple<RamDomain, 4>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3])) ? -1 : (ramBitCast<RamSigned>(a[3]) > ramBitCast<RamSigned>(b[3])) ? 1 :(0))));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))|| (ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2])) && ((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3])))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]))&&(ramBitCast<RamSigned>(a[3]) == ramBitCast<RamSigned>(b[3]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_1111(lower,upper,h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 4 direct b-tree index 0 lex-order [0,1,2,3]\n";
ind_0.printStats(o);
}
};
struct t_btree_ii__0_1__11 {
using t_tuple = Tuple<RamDomain, 2>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_11(lower,upper,h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 2 direct b-tree index 0 lex-order [0,1]\n";
ind_0.printStats(o);
}
};
struct t_btree_iii__1_2__1_0_2__011__010__110__111 {
using t_tuple = Tuple<RamDomain, 3>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]));
 }
};
using t_ind_0 = btree_multiset<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
struct t_comparator_1{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :(0)));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]));
 }
};
using t_ind_1 = btree_set<t_tuple,t_comparator_1>;
t_ind_1 ind_1;
using iterator = t_ind_1::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
t_ind_1::operation_hints hints_1_lower;
t_ind_1::operation_hints hints_1_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_1.insert(t, h.hints_1_lower)) {
ind_0.insert(t, h.hints_0_lower);
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
bool contains(const t_tuple& t, context& h) const {
return ind_1.contains(t, h.hints_1_lower);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_1.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_1.find(t, h.hints_1_lower);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<t_ind_0::iterator> lowerUpperRange_011(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> lowerUpperRange_011(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_011(lower,upper,h);
}
range<t_ind_1::iterator> lowerUpperRange_010(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_1 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_1.end(), ind_1.end());
}
return make_range(ind_1.lower_bound(lower, h.hints_1_lower), ind_1.upper_bound(upper, h.hints_1_upper));
}
range<t_ind_1::iterator> lowerUpperRange_010(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_010(lower,upper,h);
}
range<t_ind_1::iterator> lowerUpperRange_110(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_1 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_1.end(), ind_1.end());
}
return make_range(ind_1.lower_bound(lower, h.hints_1_lower), ind_1.upper_bound(upper, h.hints_1_upper));
}
range<t_ind_1::iterator> lowerUpperRange_110(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_110(lower,upper,h);
}
range<t_ind_1::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_1 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_1.find(lower, h.hints_1_lower);
    auto fin = ind_1.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_1.end(), ind_1.end());
}
return make_range(ind_1.lower_bound(lower, h.hints_1_lower), ind_1.upper_bound(upper, h.hints_1_upper));
}
range<t_ind_1::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_111(lower,upper,h);
}
bool empty() const {
return ind_1.empty();
}
std::vector<range<iterator>> partition() const {
return ind_1.getChunks(400);
}
void purge() {
ind_0.clear();
ind_1.clear();
}
iterator begin() const {
return ind_1.begin();
}
iterator end() const {
return ind_1.end();
}
void printStatistics(std::ostream& o) const {
o << " arity 3 direct b-tree index 0 lex-order [1,2]\n";
ind_0.printStats(o);
o << " arity 3 direct b-tree index 1 lex-order [1,0,2]\n";
ind_1.printStats(o);
}
};

class Sf_relation_graph : public SouffleProgram {
private:
static inline bool regex_wrapper(const std::string& pattern, const std::string& text) {
   bool result = false; 
   try { result = std::regex_match(text, std::regex(pattern)); } catch(...) { 
     std::cerr << "warning: wrong pattern provided for match(\"" << pattern << "\",\"" << text << "\").\n";
}
   return result;
}
private:
static inline std::string substr_wrapper(const std::string& str, size_t idx, size_t len) {
   std::string result; 
   try { result = str.substr(idx,len); } catch(...) { 
     std::cerr << "warning: wrong index position provided by substr(\"";
     std::cerr << str << "\"," << (int32_t)idx << "," << (int32_t)len << ") functor.\n";
   } return result;
}
public:
// -- initialize symbol table --
SymbolTable symTable{
	R"_(<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>)_",
	R"_(<http://www.w3.org/2002/07/owl#TransitiveProperty>)_",
	R"_(<http://www.w3.org/2000/01/rdf-schema#subClassOf>)_",
	R"_(<http://www.w3.org/1999/02/22-rdf-syntax-ns#first>)_",
	R"_(<http://www.w3.org/1999/02/22-rdf-syntax-ns#rest>)_",
	R"_(<http://www.w3.org/1999/02/22-rdf-syntax-ns#nil>)_",
	R"_(<http://www.w3.org/2002/07/owl#propertyChainAxiom>)_",
	R"_(<http://www.w3.org/2000/01/rdf-schema#subPropertyOf>)_",
	R"_(<http://www.w3.org/2002/07/owl#Class>)_",
	R"_(<http://www.w3.org/2002/07/owl#NamedIndividual>)_",
	R"_(<http://www.w3.org/2002/07/owl#someValuesFrom>)_",
	R"_(<http://www.w3.org/2002/07/owl#onProperty>)_",
	R"_(expected)_",
	R"_(unexpected)_",
};// -- initialize record table --
RecordTable recordTable;
// -- Table: @delta_edge
Own<t_btree_iii__0_1_2__100__111> rel_1_delta_edge = mk<t_btree_iii__0_1_2__100__111>();
// -- Table: @delta_isa_inf
Own<t_btree_ii__0_1__11__10> rel_2_delta_isa_inf = mk<t_btree_ii__0_1__11__10>();
// -- Table: @delta_subPropertyOf_tr
Own<t_btree_ii__0_1__11__10> rel_3_delta_subPropertyOf_tr = mk<t_btree_ii__0_1__11__10>();
// -- Table: @new_edge
Own<t_btree_iii__0_1_2__100__111> rel_4_new_edge = mk<t_btree_iii__0_1_2__100__111>();
// -- Table: @new_isa_inf
Own<t_btree_ii__0_1__11__10> rel_5_new_isa_inf = mk<t_btree_ii__0_1__11__10>();
// -- Table: @new_subPropertyOf_tr
Own<t_btree_ii__0_1__11__10> rel_6_new_subPropertyOf_tr = mk<t_btree_ii__0_1__11__10>();
// -- Table: __agg_rel_0
Own<t_btree_i__0__1> rel_7_agg_rel_0 = mk<t_btree_i__0__1>();
souffle::RelationWrapper<0,t_btree_i__0__1,Tuple<RamDomain,1>,1,0> wrapper_rel_7_agg_rel_0;
// -- Table: __agg_rel_1
Own<t_btree_i__0__1> rel_8_agg_rel_1 = mk<t_btree_i__0__1>();
souffle::RelationWrapper<1,t_btree_i__0__1,Tuple<RamDomain,1>,1,0> wrapper_rel_8_agg_rel_1;
// -- Table: asserted_edge
Own<t_btree_iii__0_1_2__111> rel_9_asserted_edge = mk<t_btree_iii__0_1_2__111>();
souffle::RelationWrapper<2,t_btree_iii__0_1_2__111,Tuple<RamDomain,3>,3,0> wrapper_rel_9_asserted_edge;
// -- Table: chain
Own<t_btree_iii__1_2_0__011__111> rel_10_chain = mk<t_btree_iii__1_2_0__011__111>();
souffle::RelationWrapper<3,t_btree_iii__1_2_0__011__111,Tuple<RamDomain,3>,3,0> wrapper_rel_10_chain;
// -- Table: edge
Own<t_btree_iii__0_1_2__100__111> rel_11_edge = mk<t_btree_iii__0_1_2__100__111>();
souffle::RelationWrapper<4,t_btree_iii__0_1_2__100__111,Tuple<RamDomain,3>,3,0> wrapper_rel_11_edge;
// -- Table: expected
Own<t_btree_iii__0_1_2__111> rel_12_expected = mk<t_btree_iii__0_1_2__111>();
souffle::RelationWrapper<5,t_btree_iii__0_1_2__111,Tuple<RamDomain,3>,3,0> wrapper_rel_12_expected;
// -- Table: fail
Own<t_btree_iiii__0_1_2_3__1111> rel_13_fail = mk<t_btree_iiii__0_1_2_3__1111>();
souffle::RelationWrapper<6,t_btree_iiii__0_1_2_3__1111,Tuple<RamDomain,4>,4,0> wrapper_rel_13_fail;
// -- Table: isa
Own<t_btree_ii__0_1__11> rel_14_isa = mk<t_btree_ii__0_1__11>();
souffle::RelationWrapper<7,t_btree_ii__0_1__11,Tuple<RamDomain,2>,2,0> wrapper_rel_14_isa;
// -- Table: isa_inf
Own<t_btree_ii__0_1__11__10> rel_15_isa_inf = mk<t_btree_ii__0_1__11__10>();
souffle::RelationWrapper<8,t_btree_ii__0_1__11__10,Tuple<RamDomain,2>,2,0> wrapper_rel_15_isa_inf;
// -- Table: owl_class
Own<t_btree_i__0__1> rel_16_owl_class = mk<t_btree_i__0__1>();
souffle::RelationWrapper<9,t_btree_i__0__1,Tuple<RamDomain,1>,1,0> wrapper_rel_16_owl_class;
// -- Table: owl_named_entity
Own<t_btree_i__0__1> rel_17_owl_named_entity = mk<t_btree_i__0__1>();
souffle::RelationWrapper<10,t_btree_i__0__1,Tuple<RamDomain,1>,1,0> wrapper_rel_17_owl_named_entity;
// -- Table: owl_named_individual
Own<t_btree_i__0__1> rel_18_owl_named_individual = mk<t_btree_i__0__1>();
souffle::RelationWrapper<11,t_btree_i__0__1,Tuple<RamDomain,1>,1,0> wrapper_rel_18_owl_named_individual;
// -- Table: pass
Own<t_btree_iiii__0_1_2_3__1111> rel_19_pass = mk<t_btree_iiii__0_1_2_3__1111>();
souffle::RelationWrapper<12,t_btree_iiii__0_1_2_3__1111,Tuple<RamDomain,4>,4,0> wrapper_rel_19_pass;
// -- Table: rdf
Own<t_btree_iii__1_2__1_0_2__011__010__110__111> rel_20_rdf = mk<t_btree_iii__1_2__1_0_2__011__010__110__111>();
souffle::RelationWrapper<13,t_btree_iii__1_2__1_0_2__011__010__110__111,Tuple<RamDomain,3>,3,0> wrapper_rel_20_rdf;
// -- Table: subClassOf
Own<t_btree_ii__0_1__11> rel_21_subClassOf = mk<t_btree_ii__0_1__11>();
souffle::RelationWrapper<14,t_btree_ii__0_1__11,Tuple<RamDomain,2>,2,0> wrapper_rel_21_subClassOf;
// -- Table: subPropertyOf
Own<t_btree_ii__0_1__11> rel_22_subPropertyOf = mk<t_btree_ii__0_1__11>();
souffle::RelationWrapper<15,t_btree_ii__0_1__11,Tuple<RamDomain,2>,2,0> wrapper_rel_22_subPropertyOf;
// -- Table: subPropertyOf_tr
Own<t_btree_ii__0_1__11__10> rel_23_subPropertyOf_tr = mk<t_btree_ii__0_1__11__10>();
souffle::RelationWrapper<16,t_btree_ii__0_1__11__10,Tuple<RamDomain,2>,2,0> wrapper_rel_23_subPropertyOf_tr;
// -- Table: test_summary
Own<t_btree_ii__0_1__11> rel_24_test_summary = mk<t_btree_ii__0_1__11>();
souffle::RelationWrapper<17,t_btree_ii__0_1__11,Tuple<RamDomain,2>,2,0> wrapper_rel_24_test_summary;
// -- Table: transitive
Own<t_btree_i__0__1> rel_25_transitive = mk<t_btree_i__0__1>();
souffle::RelationWrapper<18,t_btree_i__0__1,Tuple<RamDomain,1>,1,0> wrapper_rel_25_transitive;
// -- Table: unexpected
Own<t_btree_iii__0_1_2__111> rel_26_unexpected = mk<t_btree_iii__0_1_2__111>();
souffle::RelationWrapper<19,t_btree_iii__0_1_2__111,Tuple<RamDomain,3>,3,0> wrapper_rel_26_unexpected;
public:
Sf_relation_graph() : 
wrapper_rel_7_agg_rel_0(*rel_7_agg_rel_0,symTable,"__agg_rel_0",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"z"}}),

wrapper_rel_8_agg_rel_1(*rel_8_agg_rel_1,symTable,"__agg_rel_1",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"z0"}}),

wrapper_rel_9_asserted_edge(*rel_9_asserted_edge,symTable,"asserted_edge",std::array<const char *,3>{{"s:symbol","s:symbol","s:symbol"}},std::array<const char *,3>{{"s","p","o"}}),

wrapper_rel_10_chain(*rel_10_chain,symTable,"chain",std::array<const char *,3>{{"s:symbol","s:symbol","s:symbol"}},std::array<const char *,3>{{"p","p1","p2"}}),

wrapper_rel_11_edge(*rel_11_edge,symTable,"edge",std::array<const char *,3>{{"s:symbol","s:symbol","s:symbol"}},std::array<const char *,3>{{"s","p","o"}}),

wrapper_rel_12_expected(*rel_12_expected,symTable,"expected",std::array<const char *,3>{{"s:symbol","s:symbol","s:symbol"}},std::array<const char *,3>{{"s","p","o"}}),

wrapper_rel_13_fail(*rel_13_fail,symTable,"fail",std::array<const char *,4>{{"s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,4>{{"test","s","p","o"}}),

wrapper_rel_14_isa(*rel_14_isa,symTable,"isa",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"s","o"}}),

wrapper_rel_15_isa_inf(*rel_15_isa_inf,symTable,"isa_inf",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"s","o"}}),

wrapper_rel_16_owl_class(*rel_16_owl_class,symTable,"owl_class",std::array<const char *,1>{{"s:symbol"}},std::array<const char *,1>{{"s"}}),

wrapper_rel_17_owl_named_entity(*rel_17_owl_named_entity,symTable,"owl_named_entity",std::array<const char *,1>{{"s:symbol"}},std::array<const char *,1>{{"s"}}),

wrapper_rel_18_owl_named_individual(*rel_18_owl_named_individual,symTable,"owl_named_individual",std::array<const char *,1>{{"s:symbol"}},std::array<const char *,1>{{"s"}}),

wrapper_rel_19_pass(*rel_19_pass,symTable,"pass",std::array<const char *,4>{{"s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,4>{{"test","s","p","o"}}),

wrapper_rel_20_rdf(*rel_20_rdf,symTable,"rdf",std::array<const char *,3>{{"s:symbol","s:symbol","s:symbol"}},std::array<const char *,3>{{"s","p","o"}}),

wrapper_rel_21_subClassOf(*rel_21_subClassOf,symTable,"subClassOf",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"s","o"}}),

wrapper_rel_22_subPropertyOf(*rel_22_subPropertyOf,symTable,"subPropertyOf",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"s","o"}}),

wrapper_rel_23_subPropertyOf_tr(*rel_23_subPropertyOf_tr,symTable,"subPropertyOf_tr",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"s","o"}}),

wrapper_rel_24_test_summary(*rel_24_test_summary,symTable,"test_summary",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"n_pass","n_fail"}}),

wrapper_rel_25_transitive(*rel_25_transitive,symTable,"transitive",std::array<const char *,1>{{"s:symbol"}},std::array<const char *,1>{{"p"}}),

wrapper_rel_26_unexpected(*rel_26_unexpected,symTable,"unexpected",std::array<const char *,3>{{"s:symbol","s:symbol","s:symbol"}},std::array<const char *,3>{{"s","p","o"}}){
addRelation("__agg_rel_0",&wrapper_rel_7_agg_rel_0,false,false);
addRelation("__agg_rel_1",&wrapper_rel_8_agg_rel_1,false,false);
addRelation("asserted_edge",&wrapper_rel_9_asserted_edge,false,true);
addRelation("chain",&wrapper_rel_10_chain,false,true);
addRelation("edge",&wrapper_rel_11_edge,false,true);
addRelation("expected",&wrapper_rel_12_expected,true,false);
addRelation("fail",&wrapper_rel_13_fail,false,true);
addRelation("isa",&wrapper_rel_14_isa,false,false);
addRelation("isa_inf",&wrapper_rel_15_isa_inf,false,false);
addRelation("owl_class",&wrapper_rel_16_owl_class,false,false);
addRelation("owl_named_entity",&wrapper_rel_17_owl_named_entity,false,false);
addRelation("owl_named_individual",&wrapper_rel_18_owl_named_individual,false,false);
addRelation("pass",&wrapper_rel_19_pass,false,true);
addRelation("rdf",&wrapper_rel_20_rdf,true,false);
addRelation("subClassOf",&wrapper_rel_21_subClassOf,false,false);
addRelation("subPropertyOf",&wrapper_rel_22_subPropertyOf,false,false);
addRelation("subPropertyOf_tr",&wrapper_rel_23_subPropertyOf_tr,false,false);
addRelation("test_summary",&wrapper_rel_24_test_summary,false,true);
addRelation("transitive",&wrapper_rel_25_transitive,false,false);
addRelation("unexpected",&wrapper_rel_26_unexpected,true,false);
}
~Sf_relation_graph() {
}
private:
std::string inputDirectory;
std::string outputDirectory;
bool performIO;
std::atomic<RamDomain> ctr{};

std::atomic<size_t> iter{};
void runFunction(std::string inputDirectoryArg = "", std::string outputDirectoryArg = "", bool performIOArg = false) {
this->inputDirectory = inputDirectoryArg;
this->outputDirectory = outputDirectoryArg;
this->performIO = performIOArg;
SignalHandler::instance()->set();
#if defined(_OPENMP)
if (getNumThreads() > 0) {omp_set_num_threads(getNumThreads());}
#endif

// -- query evaluation --
{
 std::vector<RamDomain> args, ret;
subroutine_0(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_1(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_12(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_13(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_14(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_15(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_16(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_17(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_18(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_19(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_2(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_3(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_4(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_5(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_6(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_7(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_8(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_9(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_10(args, ret);
}
{
 std::vector<RamDomain> args, ret;
subroutine_11(args, ret);
}

// -- relation hint statistics --
SignalHandler::instance()->reset();
}
public:
void run() override { runFunction("", "", false); }
public:
void runAll(std::string inputDirectoryArg = "", std::string outputDirectoryArg = "") override { runFunction(inputDirectoryArg, outputDirectoryArg, true);
}
public:
void printAll(std::string outputDirectoryArg = "") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","p\tp1\tp2"},{"name","chain"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"p\", \"p1\", \"p2\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_10_chain);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"name","asserted_edge"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_9_asserted_edge);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"name","edge"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_11_edge);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","test\ts\tp\to"},{"name","fail"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"params\": [\"test\", \"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_13_fail);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","test\ts\tp\to"},{"name","pass"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"params\": [\"test\", \"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_19_pass);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","n_pass\tn_fail"},{"name","test_summary"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 2, \"auxArity\": 0, \"params\": [\"n_pass\", \"n_fail\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 2, \"auxArity\": 0, \"types\": [\"i:number\", \"i:number\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_24_test_summary);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectoryArg = "") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"fact-dir","."},{"name","rdf"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_20_rdf);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"fact-dir","."},{"name","unexpected"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_26_unexpected);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"fact-dir","."},{"name","expected"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_12_expected);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs() override {
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "rdf";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_20_rdf);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "unexpected";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_26_unexpected);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "expected";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_12_expected);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs() override {
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "chain";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_10_chain);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "asserted_edge";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_9_asserted_edge);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "edge";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_11_edge);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "fail";
rwOperation["types"] = "{\"relation\": {\"arity\": 4, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_13_fail);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "pass";
rwOperation["types"] = "{\"relation\": {\"arity\": 4, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\", \"s:symbol\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_19_pass);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "test_summary";
rwOperation["types"] = "{\"relation\": {\"arity\": 2, \"auxArity\": 0, \"types\": [\"i:number\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_24_test_summary);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) override {
if (name == "stratum_0") {
subroutine_0(args, ret);
return;}
if (name == "stratum_1") {
subroutine_1(args, ret);
return;}
if (name == "stratum_10") {
subroutine_2(args, ret);
return;}
if (name == "stratum_11") {
subroutine_3(args, ret);
return;}
if (name == "stratum_12") {
subroutine_4(args, ret);
return;}
if (name == "stratum_13") {
subroutine_5(args, ret);
return;}
if (name == "stratum_14") {
subroutine_6(args, ret);
return;}
if (name == "stratum_15") {
subroutine_7(args, ret);
return;}
if (name == "stratum_16") {
subroutine_8(args, ret);
return;}
if (name == "stratum_17") {
subroutine_9(args, ret);
return;}
if (name == "stratum_18") {
subroutine_10(args, ret);
return;}
if (name == "stratum_19") {
subroutine_11(args, ret);
return;}
if (name == "stratum_2") {
subroutine_12(args, ret);
return;}
if (name == "stratum_3") {
subroutine_13(args, ret);
return;}
if (name == "stratum_4") {
subroutine_14(args, ret);
return;}
if (name == "stratum_5") {
subroutine_15(args, ret);
return;}
if (name == "stratum_6") {
subroutine_16(args, ret);
return;}
if (name == "stratum_7") {
subroutine_17(args, ret);
return;}
if (name == "stratum_8") {
subroutine_18(args, ret);
return;}
if (name == "stratum_9") {
subroutine_19(args, ret);
return;}
fatal("unknown subroutine");
}
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_0(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"fact-dir","."},{"name","rdf"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_20_rdf);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_1(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(transitive(p) :- 
   rdf(p,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>","<http://www.w3.org/2002/07/owl#TransitiveProperty>").
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [31:1-31:136])_");
if(!(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_25_transitive_op_ctxt,rel_25_transitive->createContext());
auto range = rel_20_rdf->lowerUpperRange_011(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(1))}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env0 : range) {
Tuple<RamDomain,1> tuple{{ramBitCast(env0[0])}};
rel_25_transitive->insert(tuple,READ_OP_CONTEXT(rel_25_transitive_op_ctxt));
}
}
();}
SignalHandler::instance()->setMsg(R"_(transitive("<http://www.w3.org/2000/01/rdf-schema#subClassOf>").
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [32:1-32:67])_");
[&](){
CREATE_OP_CONTEXT(rel_25_transitive_op_ctxt,rel_25_transitive->createContext());
Tuple<RamDomain,1> tuple{{ramBitCast(RamSigned(2))}};
rel_25_transitive->insert(tuple,READ_OP_CONTEXT(rel_25_transitive_op_ctxt));
}
();}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_2(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(owl_named_entity(x) :- 
   owl_class(x).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [28:1-28:63])_");
if(!(rel_16_owl_class->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_16_owl_class_op_ctxt,rel_16_owl_class->createContext());
CREATE_OP_CONTEXT(rel_17_owl_named_entity_op_ctxt,rel_17_owl_named_entity->createContext());
for(const auto& env0 : *rel_16_owl_class) {
Tuple<RamDomain,1> tuple{{ramBitCast(env0[0])}};
rel_17_owl_named_entity->insert(tuple,READ_OP_CONTEXT(rel_17_owl_named_entity_op_ctxt));
}
}
();}
SignalHandler::instance()->setMsg(R"_(owl_named_entity(x) :- 
   owl_named_individual(x).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [28:1-28:63])_");
if(!(rel_18_owl_named_individual->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_18_owl_named_individual_op_ctxt,rel_18_owl_named_individual->createContext());
CREATE_OP_CONTEXT(rel_17_owl_named_entity_op_ctxt,rel_17_owl_named_entity->createContext());
for(const auto& env0 : *rel_18_owl_named_individual) {
Tuple<RamDomain,1> tuple{{ramBitCast(env0[0])}};
rel_17_owl_named_entity->insert(tuple,READ_OP_CONTEXT(rel_17_owl_named_entity_op_ctxt));
}
}
();}
if (performIO) rel_18_owl_named_individual->purge();
if (performIO) rel_16_owl_class->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_3(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(asserted_edge(s,p,o) :- 
   rdf(s,p,o),
   owl_named_entity(s),
   owl_named_entity(o).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [24:1-24:82])_");
if(!(rel_17_owl_named_entity->empty()) && !(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_17_owl_named_entity_op_ctxt,rel_17_owl_named_entity->createContext());
CREATE_OP_CONTEXT(rel_9_asserted_edge_op_ctxt,rel_9_asserted_edge->createContext());
for(const auto& env0 : *rel_20_rdf) {
if( rel_17_owl_named_entity->contains(Tuple<RamDomain,1>{{ramBitCast(env0[2])}},READ_OP_CONTEXT(rel_17_owl_named_entity_op_ctxt)) && rel_17_owl_named_entity->contains(Tuple<RamDomain,1>{{ramBitCast(env0[0])}},READ_OP_CONTEXT(rel_17_owl_named_entity_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_9_asserted_edge->insert(tuple,READ_OP_CONTEXT(rel_9_asserted_edge_op_ctxt));
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(asserted_edge(s,p,o) :- 
   subClassOf(s,restr),
   rdf(restr,"<http://www.w3.org/2002/07/owl#onProperty>",p),
   rdf(restr,"<http://www.w3.org/2002/07/owl#someValuesFrom>",o).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [27:1-29:74])_");
if(!(rel_20_rdf->empty()) && !(rel_21_subClassOf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_21_subClassOf_op_ctxt,rel_21_subClassOf->createContext());
CREATE_OP_CONTEXT(rel_9_asserted_edge_op_ctxt,rel_9_asserted_edge->createContext());
for(const auto& env0 : *rel_21_subClassOf) {
auto range = rel_20_rdf->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(env0[1]), ramBitCast(RamSigned(11)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[1]), ramBitCast(RamSigned(11)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env1 : range) {
auto range = rel_20_rdf->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(env0[1]), ramBitCast(RamSigned(10)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[1]), ramBitCast(RamSigned(10)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env1[2]),ramBitCast(env2[2])}};
rel_9_asserted_edge->insert(tuple,READ_OP_CONTEXT(rel_9_asserted_edge_op_ctxt));
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"name","asserted_edge"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_9_asserted_edge);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) rel_21_subClassOf->purge();
if (performIO) rel_17_owl_named_entity->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_4(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(edge(s,p,o) :- 
   asserted_edge(s,p,o).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [35:1-35:39])_");
if(!(rel_9_asserted_edge->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_asserted_edge_op_ctxt,rel_9_asserted_edge->createContext());
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
for(const auto& env0 : *rel_9_asserted_edge) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_11_edge->insert(tuple,READ_OP_CONTEXT(rel_11_edge_op_ctxt));
}
}
();}
SignalHandler::instance()->setMsg(R"_(edge(s,"<http://www.w3.org/2000/01/rdf-schema#subClassOf>",s) :- 
   rdf(s,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>","<http://www.w3.org/2002/07/owl#Class>").
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [46:1-46:175])_");
if(!(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
auto range = rel_20_rdf->lowerUpperRange_011(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(8))}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(8))}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env0 : range) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(RamSigned(2)),ramBitCast(env0[0])}};
rel_11_edge->insert(tuple,READ_OP_CONTEXT(rel_11_edge_op_ctxt));
}
}
();}
[&](){
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_1_delta_edge_op_ctxt,rel_1_delta_edge->createContext());
for(const auto& env0 : *rel_11_edge) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_1_delta_edge->insert(tuple,READ_OP_CONTEXT(rel_1_delta_edge_op_ctxt));
}
}
();iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(edge(s,p,o) :- 
   edge(s,p1,o),
   subPropertyOf_tr(p1,p).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [36:1-36:57])_");
if(!(rel_1_delta_edge->empty()) && !(rel_23_subPropertyOf_tr->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt,rel_23_subPropertyOf_tr->createContext());
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_1_delta_edge_op_ctxt,rel_1_delta_edge->createContext());
CREATE_OP_CONTEXT(rel_4_new_edge_op_ctxt,rel_4_new_edge->createContext());
for(const auto& env0 : *rel_1_delta_edge) {
auto range = rel_23_subPropertyOf_tr->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env1[1]),ramBitCast(env0[2])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env1[1]),ramBitCast(env0[2])}};
rel_4_new_edge->insert(tuple,READ_OP_CONTEXT(rel_4_new_edge_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(edge(s,p,o) :- 
   edge(s,p1,z),
   edge(z,p2,o),
   chain(p,p1,p2).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [39:1-39:67])_");
if(!(rel_10_chain->empty()) && !(rel_1_delta_edge->empty()) && !(rel_11_edge->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_10_chain_op_ctxt,rel_10_chain->createContext());
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_1_delta_edge_op_ctxt,rel_1_delta_edge->createContext());
CREATE_OP_CONTEXT(rel_4_new_edge_op_ctxt,rel_4_new_edge->createContext());
for(const auto& env0 : *rel_1_delta_edge) {
auto range = rel_11_edge->lowerUpperRange_100(Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_11_edge_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_1_delta_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[2]),ramBitCast(env1[1]),ramBitCast(env1[2])}},READ_OP_CONTEXT(rel_1_delta_edge_op_ctxt)))) {
auto range = rel_10_chain->lowerUpperRange_011(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(env0[1]), ramBitCast(env1[1])}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(env0[1]), ramBitCast(env1[1])}},READ_OP_CONTEXT(rel_10_chain_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env2[0]),ramBitCast(env1[2])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env2[0]),ramBitCast(env1[2])}};
rel_4_new_edge->insert(tuple,READ_OP_CONTEXT(rel_4_new_edge_op_ctxt));
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(edge(s,p,o) :- 
   edge(s,p1,z),
   edge(z,p2,o),
   chain(p,p1,p2).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [39:1-39:67])_");
if(!(rel_10_chain->empty()) && !(rel_11_edge->empty()) && !(rel_1_delta_edge->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_10_chain_op_ctxt,rel_10_chain->createContext());
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_1_delta_edge_op_ctxt,rel_1_delta_edge->createContext());
CREATE_OP_CONTEXT(rel_4_new_edge_op_ctxt,rel_4_new_edge->createContext());
for(const auto& env0 : *rel_11_edge) {
auto range = rel_1_delta_edge->lowerUpperRange_100(Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_1_delta_edge_op_ctxt));
for(const auto& env1 : range) {
auto range = rel_10_chain->lowerUpperRange_011(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(env0[1]), ramBitCast(env1[1])}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(env0[1]), ramBitCast(env1[1])}},READ_OP_CONTEXT(rel_10_chain_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env2[0]),ramBitCast(env1[2])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env2[0]),ramBitCast(env1[2])}};
rel_4_new_edge->insert(tuple,READ_OP_CONTEXT(rel_4_new_edge_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(edge(s,p,o) :- 
   isa_inf(s,s1),
   edge(s1,p,o1),
   isa_inf(o1,o).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [43:1-43:66])_");
if(!(rel_15_isa_inf->empty()) && !(rel_1_delta_edge->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_15_isa_inf_op_ctxt,rel_15_isa_inf->createContext());
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_1_delta_edge_op_ctxt,rel_1_delta_edge->createContext());
CREATE_OP_CONTEXT(rel_4_new_edge_op_ctxt,rel_4_new_edge->createContext());
for(const auto& env0 : *rel_15_isa_inf) {
auto range = rel_1_delta_edge->lowerUpperRange_100(Tuple<RamDomain,3>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_1_delta_edge_op_ctxt));
for(const auto& env1 : range) {
auto range = rel_15_isa_inf->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env1[2]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env1[2]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_15_isa_inf_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env1[1]),ramBitCast(env2[1])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env1[1]),ramBitCast(env2[1])}};
rel_4_new_edge->insert(tuple,READ_OP_CONTEXT(rel_4_new_edge_op_ctxt));
}
}
}
}
}
();}
if(rel_4_new_edge->empty()) break;
[&](){
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_4_new_edge_op_ctxt,rel_4_new_edge->createContext());
for(const auto& env0 : *rel_4_new_edge) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_11_edge->insert(tuple,READ_OP_CONTEXT(rel_11_edge_op_ctxt));
}
}
();std::swap(rel_1_delta_edge, rel_4_new_edge);
rel_4_new_edge->purge();
iter++;
}
iter = 0;
rel_1_delta_edge->purge();
rel_4_new_edge->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"name","edge"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_11_edge);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) rel_20_rdf->purge();
if (performIO) rel_10_chain->purge();
if (performIO) rel_23_subPropertyOf_tr->purge();
if (performIO) rel_9_asserted_edge->purge();
if (performIO) rel_15_isa_inf->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_5(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"fact-dir","."},{"name","expected"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_12_expected);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_6(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tp\to"},{"fact-dir","."},{"name","unexpected"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_26_unexpected);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_7(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(fail("expected",s,p,o) :- 
   expected(s,p,o),
   !edge(s,p,o).
in file /Users/cjm/repos/souffle-test/src/test_harness.dl [15:1-15:59])_");
if(!(rel_12_expected->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_12_expected_op_ctxt,rel_12_expected->createContext());
CREATE_OP_CONTEXT(rel_13_fail_op_ctxt,rel_13_fail->createContext());
for(const auto& env0 : *rel_12_expected) {
if( !(rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt)))) {
Tuple<RamDomain,4> tuple{{ramBitCast(RamSigned(12)),ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_13_fail->insert(tuple,READ_OP_CONTEXT(rel_13_fail_op_ctxt));
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(fail("unexpected",s,p,o) :- 
   unexpected(s,p,o),
   edge(s,p,o).
in file /Users/cjm/repos/souffle-test/src/test_harness.dl [16:1-16:61])_");
if(!(rel_26_unexpected->empty()) && !(rel_11_edge->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_26_unexpected_op_ctxt,rel_26_unexpected->createContext());
CREATE_OP_CONTEXT(rel_13_fail_op_ctxt,rel_13_fail->createContext());
for(const auto& env0 : *rel_26_unexpected) {
if( rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt))) {
Tuple<RamDomain,4> tuple{{ramBitCast(RamSigned(13)),ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_13_fail->insert(tuple,READ_OP_CONTEXT(rel_13_fail_op_ctxt));
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","test\ts\tp\to"},{"name","fail"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"params\": [\"test\", \"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_13_fail);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_8(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(__agg_rel_1(count : { fail(_,_,_,_) }).
in file  [0:0-0:0])_");
[&](){
CREATE_OP_CONTEXT(rel_13_fail_op_ctxt,rel_13_fail->createContext());
CREATE_OP_CONTEXT(rel_8_agg_rel_1_op_ctxt,rel_8_agg_rel_1->createContext());
Tuple<RamDomain,1> env0;
env0[0] = rel_13_fail->size();
Tuple<RamDomain,1> tuple{{ramBitCast(env0[0])}};
rel_8_agg_rel_1->insert(tuple,READ_OP_CONTEXT(rel_8_agg_rel_1_op_ctxt));
}
();if (performIO) rel_13_fail->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_9(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(pass("expected",s,p,o) :- 
   expected(s,p,o),
   edge(s,p,o).
in file /Users/cjm/repos/souffle-test/src/test_harness.dl [17:1-17:57])_");
if(!(rel_12_expected->empty()) && !(rel_11_edge->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_12_expected_op_ctxt,rel_12_expected->createContext());
CREATE_OP_CONTEXT(rel_19_pass_op_ctxt,rel_19_pass->createContext());
for(const auto& env0 : *rel_12_expected) {
if( rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt))) {
Tuple<RamDomain,4> tuple{{ramBitCast(RamSigned(12)),ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_19_pass->insert(tuple,READ_OP_CONTEXT(rel_19_pass_op_ctxt));
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(pass("unexpected",s,p,o) :- 
   unexpected(s,p,o),
   !edge(s,p,o).
in file /Users/cjm/repos/souffle-test/src/test_harness.dl [18:1-18:63])_");
if(!(rel_26_unexpected->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_11_edge_op_ctxt,rel_11_edge->createContext());
CREATE_OP_CONTEXT(rel_26_unexpected_op_ctxt,rel_26_unexpected->createContext());
CREATE_OP_CONTEXT(rel_19_pass_op_ctxt,rel_19_pass->createContext());
for(const auto& env0 : *rel_26_unexpected) {
if( !(rel_11_edge->contains(Tuple<RamDomain,3>{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}},READ_OP_CONTEXT(rel_11_edge_op_ctxt)))) {
Tuple<RamDomain,4> tuple{{ramBitCast(RamSigned(13)),ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_19_pass->insert(tuple,READ_OP_CONTEXT(rel_19_pass_op_ctxt));
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","test\ts\tp\to"},{"name","pass"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"params\": [\"test\", \"s\", \"p\", \"o\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 4, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_19_pass);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) rel_26_unexpected->purge();
if (performIO) rel_12_expected->purge();
if (performIO) rel_11_edge->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_10(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(__agg_rel_0(count : { pass(_,_,_,_) }).
in file  [0:0-0:0])_");
[&](){
CREATE_OP_CONTEXT(rel_7_agg_rel_0_op_ctxt,rel_7_agg_rel_0->createContext());
CREATE_OP_CONTEXT(rel_19_pass_op_ctxt,rel_19_pass->createContext());
Tuple<RamDomain,1> env0;
env0[0] = rel_19_pass->size();
Tuple<RamDomain,1> tuple{{ramBitCast(env0[0])}};
rel_7_agg_rel_0->insert(tuple,READ_OP_CONTEXT(rel_7_agg_rel_0_op_ctxt));
}
();if (performIO) rel_19_pass->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_11(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(test_summary(z,z0) :- 
   __agg_rel_0(z),
   __agg_rel_1(z0).
in file /Users/cjm/repos/souffle-test/src/test_harness.dl [22:1-24:36])_");
if(!(rel_7_agg_rel_0->empty()) && !(rel_8_agg_rel_1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_8_agg_rel_1_op_ctxt,rel_8_agg_rel_1->createContext());
CREATE_OP_CONTEXT(rel_7_agg_rel_0_op_ctxt,rel_7_agg_rel_0->createContext());
CREATE_OP_CONTEXT(rel_24_test_summary_op_ctxt,rel_24_test_summary->createContext());
for(const auto& env0 : *rel_7_agg_rel_0) {
for(const auto& env1 : *rel_8_agg_rel_1) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env1[0])}};
rel_24_test_summary->insert(tuple,READ_OP_CONTEXT(rel_24_test_summary_op_ctxt));
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","n_pass\tn_fail"},{"name","test_summary"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 2, \"auxArity\": 0, \"params\": [\"n_pass\", \"n_fail\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 2, \"auxArity\": 0, \"types\": [\"i:number\", \"i:number\"]}}"}});
if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_24_test_summary);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) rel_8_agg_rel_1->purge();
if (performIO) rel_7_agg_rel_0->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_12(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(chain(p,p,p) :- 
   transitive(p).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [52:1-52:33])_");
if(!(rel_25_transitive->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_25_transitive_op_ctxt,rel_25_transitive->createContext());
CREATE_OP_CONTEXT(rel_10_chain_op_ctxt,rel_10_chain->createContext());
for(const auto& env0 : *rel_25_transitive) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[0]),ramBitCast(env0[0])}};
rel_10_chain->insert(tuple,READ_OP_CONTEXT(rel_10_chain_op_ctxt));
}
}
();}
SignalHandler::instance()->setMsg(R"_(chain(p,p1,p2) :- 
   rdf(p,"<http://www.w3.org/2002/07/owl#propertyChainAxiom>",list),
   rdf(list,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#first>",p1),
   rdf(list,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#rest>",list2),
   rdf(list2,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#rest>","<http://www.w3.org/1999/02/22-rdf-syntax-ns#nil>"),
   rdf(list2,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#first>",p2).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [46:1-51:125])_");
if(!(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_10_chain_op_ctxt,rel_10_chain->createContext());
auto range = rel_20_rdf->lowerUpperRange_010(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(6)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(6)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env0 : range) {
auto range = rel_20_rdf->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast(RamSigned(3)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast(RamSigned(3)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env1 : range) {
auto range = rel_20_rdf->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast(RamSigned(4)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[2]), ramBitCast(RamSigned(4)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env2 : range) {
if( rel_20_rdf->contains(Tuple<RamDomain,3>{{ramBitCast(env2[2]),ramBitCast(RamSigned(4)),ramBitCast(RamSigned(5))}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt))) {
auto range = rel_20_rdf->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(env2[2]), ramBitCast(RamSigned(3)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env2[2]), ramBitCast(RamSigned(3)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env1[2]),ramBitCast(env3[2])}};
rel_10_chain->insert(tuple,READ_OP_CONTEXT(rel_10_chain_op_ctxt));
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","p\tp1\tp2"},{"name","chain"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"params\": [\"p\", \"p1\", \"p2\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:symbol\", \"s:symbol\", \"s:symbol\"]}}"}});
if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_10_chain);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) rel_25_transitive->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_13(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(subClassOf(s,o) :- 
   rdf(s,"<http://www.w3.org/2000/01/rdf-schema#subClassOf>",o).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [35:1-35:83])_");
if(!(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_21_subClassOf_op_ctxt,rel_21_subClassOf->createContext());
auto range = rel_20_rdf->lowerUpperRange_010(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env0 : range) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[2])}};
rel_21_subClassOf->insert(tuple,READ_OP_CONTEXT(rel_21_subClassOf_op_ctxt));
}
}
();}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_14(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(subPropertyOf(s,o) :- 
   rdf(s,"<http://www.w3.org/2000/01/rdf-schema#subPropertyOf>",o).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [38:1-38:89])_");
if(!(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_22_subPropertyOf_op_ctxt,rel_22_subPropertyOf->createContext());
auto range = rel_20_rdf->lowerUpperRange_010(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(7)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(7)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env0 : range) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[2])}};
rel_22_subPropertyOf->insert(tuple,READ_OP_CONTEXT(rel_22_subPropertyOf_op_ctxt));
}
}
();}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_15(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(subPropertyOf_tr(s,o) :- 
   subPropertyOf(s,o).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [41:1-41:45])_");
if(!(rel_22_subPropertyOf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_22_subPropertyOf_op_ctxt,rel_22_subPropertyOf->createContext());
CREATE_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt,rel_23_subPropertyOf_tr->createContext());
for(const auto& env0 : *rel_22_subPropertyOf) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_23_subPropertyOf_tr->insert(tuple,READ_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt));
}
}
();}
[&](){
CREATE_OP_CONTEXT(rel_3_delta_subPropertyOf_tr_op_ctxt,rel_3_delta_subPropertyOf_tr->createContext());
CREATE_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt,rel_23_subPropertyOf_tr->createContext());
for(const auto& env0 : *rel_23_subPropertyOf_tr) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_3_delta_subPropertyOf_tr->insert(tuple,READ_OP_CONTEXT(rel_3_delta_subPropertyOf_tr_op_ctxt));
}
}
();iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(subPropertyOf_tr(s,o) :- 
   subPropertyOf(s,z),
   subPropertyOf_tr(z,o).
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [42:1-42:68])_");
if(!(rel_22_subPropertyOf->empty()) && !(rel_3_delta_subPropertyOf_tr->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_delta_subPropertyOf_tr_op_ctxt,rel_3_delta_subPropertyOf_tr->createContext());
CREATE_OP_CONTEXT(rel_6_new_subPropertyOf_tr_op_ctxt,rel_6_new_subPropertyOf_tr->createContext());
CREATE_OP_CONTEXT(rel_22_subPropertyOf_op_ctxt,rel_22_subPropertyOf->createContext());
CREATE_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt,rel_23_subPropertyOf_tr->createContext());
for(const auto& env0 : *rel_22_subPropertyOf) {
auto range = rel_3_delta_subPropertyOf_tr->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_3_delta_subPropertyOf_tr_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_23_subPropertyOf_tr->contains(Tuple<RamDomain,2>{{ramBitCast(env0[0]),ramBitCast(env1[1])}},READ_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env1[1])}};
rel_6_new_subPropertyOf_tr->insert(tuple,READ_OP_CONTEXT(rel_6_new_subPropertyOf_tr_op_ctxt));
}
}
}
}
();}
if(rel_6_new_subPropertyOf_tr->empty()) break;
[&](){
CREATE_OP_CONTEXT(rel_6_new_subPropertyOf_tr_op_ctxt,rel_6_new_subPropertyOf_tr->createContext());
CREATE_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt,rel_23_subPropertyOf_tr->createContext());
for(const auto& env0 : *rel_6_new_subPropertyOf_tr) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_23_subPropertyOf_tr->insert(tuple,READ_OP_CONTEXT(rel_23_subPropertyOf_tr_op_ctxt));
}
}
();std::swap(rel_3_delta_subPropertyOf_tr, rel_6_new_subPropertyOf_tr);
rel_6_new_subPropertyOf_tr->purge();
iter++;
}
iter = 0;
rel_3_delta_subPropertyOf_tr->purge();
rel_6_new_subPropertyOf_tr->purge();
if (performIO) rel_22_subPropertyOf->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_16(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(owl_class(x) :- 
   rdf(x,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>","<http://www.w3.org/2002/07/owl#Class>").
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [24:1-24:122])_");
if(!(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_16_owl_class_op_ctxt,rel_16_owl_class->createContext());
auto range = rel_20_rdf->lowerUpperRange_011(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(8))}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(8))}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env0 : range) {
Tuple<RamDomain,1> tuple{{ramBitCast(env0[0])}};
rel_16_owl_class->insert(tuple,READ_OP_CONTEXT(rel_16_owl_class_op_ctxt));
}
}
();}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_17(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(isa(s,o) :- 
   subClassOf(s,o),
   owl_class(s),
   owl_class(o).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [15:1-15:57])_");
if(!(rel_16_owl_class->empty()) && !(rel_21_subClassOf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_16_owl_class_op_ctxt,rel_16_owl_class->createContext());
CREATE_OP_CONTEXT(rel_14_isa_op_ctxt,rel_14_isa->createContext());
CREATE_OP_CONTEXT(rel_21_subClassOf_op_ctxt,rel_21_subClassOf->createContext());
for(const auto& env0 : *rel_21_subClassOf) {
if( rel_16_owl_class->contains(Tuple<RamDomain,1>{{ramBitCast(env0[1])}},READ_OP_CONTEXT(rel_16_owl_class_op_ctxt)) && rel_16_owl_class->contains(Tuple<RamDomain,1>{{ramBitCast(env0[0])}},READ_OP_CONTEXT(rel_16_owl_class_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_14_isa->insert(tuple,READ_OP_CONTEXT(rel_14_isa_op_ctxt));
}
}
}
();}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_18(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(isa_inf(s,s) :- 
   owl_class(s).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [16:1-16:31])_");
if(!(rel_16_owl_class->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_16_owl_class_op_ctxt,rel_16_owl_class->createContext());
CREATE_OP_CONTEXT(rel_15_isa_inf_op_ctxt,rel_15_isa_inf->createContext());
for(const auto& env0 : *rel_16_owl_class) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[0])}};
rel_15_isa_inf->insert(tuple,READ_OP_CONTEXT(rel_15_isa_inf_op_ctxt));
}
}
();}
SignalHandler::instance()->setMsg(R"_(isa_inf(s,o) :- 
   isa(s,o).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [17:1-17:28])_");
if(!(rel_14_isa->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_14_isa_op_ctxt,rel_14_isa->createContext());
CREATE_OP_CONTEXT(rel_15_isa_inf_op_ctxt,rel_15_isa_inf->createContext());
for(const auto& env0 : *rel_14_isa) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_15_isa_inf->insert(tuple,READ_OP_CONTEXT(rel_15_isa_inf_op_ctxt));
}
}
();}
[&](){
CREATE_OP_CONTEXT(rel_15_isa_inf_op_ctxt,rel_15_isa_inf->createContext());
CREATE_OP_CONTEXT(rel_2_delta_isa_inf_op_ctxt,rel_2_delta_isa_inf->createContext());
for(const auto& env0 : *rel_15_isa_inf) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_2_delta_isa_inf->insert(tuple,READ_OP_CONTEXT(rel_2_delta_isa_inf_op_ctxt));
}
}
();iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(isa_inf(s,o) :- 
   isa(s,z),
   isa_inf(z,o).
in file /Users/cjm/repos/souffle-test/src/relation_graph.dl [18:1-18:43])_");
if(!(rel_14_isa->empty()) && !(rel_2_delta_isa_inf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_14_isa_op_ctxt,rel_14_isa->createContext());
CREATE_OP_CONTEXT(rel_15_isa_inf_op_ctxt,rel_15_isa_inf->createContext());
CREATE_OP_CONTEXT(rel_2_delta_isa_inf_op_ctxt,rel_2_delta_isa_inf->createContext());
CREATE_OP_CONTEXT(rel_5_new_isa_inf_op_ctxt,rel_5_new_isa_inf->createContext());
for(const auto& env0 : *rel_14_isa) {
auto range = rel_2_delta_isa_inf->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env0[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_2_delta_isa_inf_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_15_isa_inf->contains(Tuple<RamDomain,2>{{ramBitCast(env0[0]),ramBitCast(env1[1])}},READ_OP_CONTEXT(rel_15_isa_inf_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env1[1])}};
rel_5_new_isa_inf->insert(tuple,READ_OP_CONTEXT(rel_5_new_isa_inf_op_ctxt));
}
}
}
}
();}
if(rel_5_new_isa_inf->empty()) break;
[&](){
CREATE_OP_CONTEXT(rel_15_isa_inf_op_ctxt,rel_15_isa_inf->createContext());
CREATE_OP_CONTEXT(rel_5_new_isa_inf_op_ctxt,rel_5_new_isa_inf->createContext());
for(const auto& env0 : *rel_5_new_isa_inf) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_15_isa_inf->insert(tuple,READ_OP_CONTEXT(rel_15_isa_inf_op_ctxt));
}
}
();std::swap(rel_2_delta_isa_inf, rel_5_new_isa_inf);
rel_5_new_isa_inf->purge();
iter++;
}
iter = 0;
rel_2_delta_isa_inf->purge();
rel_5_new_isa_inf->purge();
if (performIO) rel_14_isa->purge();
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
#ifdef _MSC_VER
#pragma warning(disable: 4100)
#endif // _MSC_VER
void subroutine_19(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret) {
SignalHandler::instance()->setMsg(R"_(owl_named_individual(x) :- 
   rdf(x,"<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>","<http://www.w3.org/2002/07/owl#NamedIndividual>").
in file /Users/cjm/repos/souffle-test/src/owl_from_rdf.dl [27:1-27:143])_");
if(!(rel_20_rdf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_rdf_op_ctxt,rel_20_rdf->createContext());
CREATE_OP_CONTEXT(rel_18_owl_named_individual_op_ctxt,rel_18_owl_named_individual->createContext());
auto range = rel_20_rdf->lowerUpperRange_011(Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(9))}},Tuple<RamDomain,3>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast(RamSigned(9))}},READ_OP_CONTEXT(rel_20_rdf_op_ctxt));
for(const auto& env0 : range) {
Tuple<RamDomain,1> tuple{{ramBitCast(env0[0])}};
rel_18_owl_named_individual->insert(tuple,READ_OP_CONTEXT(rel_18_owl_named_individual_op_ctxt));
}
}
();}
}
#ifdef _MSC_VER
#pragma warning(default: 4100)
#endif // _MSC_VER
};
SouffleProgram *newInstance_relation_graph(){return new Sf_relation_graph;}
SymbolTable *getST_relation_graph(SouffleProgram *p){return &reinterpret_cast<Sf_relation_graph*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_relation_graph: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_relation_graph();
};
public:
factory_Sf_relation_graph() : ProgramFactory("relation_graph"){}
};
extern "C" {
factory_Sf_relation_graph __factory_Sf_relation_graph_instance;
}
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(src/relation_graph.dl)",
R"()",
R"()",
false,
R"()",
1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_relation_graph obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
