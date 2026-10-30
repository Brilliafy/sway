#ifndef _SWAY_LOCK_H
#define _SWAY_LOCK_H

struct sway_session_lock;

void arrange_locks(void);
void sway_session_lock_unlock(struct sway_session_lock *lock);

#endif
