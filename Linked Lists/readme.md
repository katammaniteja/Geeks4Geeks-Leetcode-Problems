
### Floyd's Cycle Detection
##### Points to note:
- fast* will enter into the loop before(or at the same time as slow*)
- Let fast* be k distance ahead of slow* when slow pointer enters the loop where k>=0
- This distance keep on increasing by one in every movement of both pointers
- When distance become length of cycle, they meet.

### Detect and Remove loop
- Detect loop using floyd cycle detection.
- move slow_p to beginning of the linked list and keep fast_p unchanged.
- now move slow_p and fast_p with same speed. The point at which the slow and fast pointer met is the first node of the loop.
