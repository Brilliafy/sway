#include <stddef.h>
#include "sway/commands.h"
#include "sway/lock.h"
#include "sway/server.h"
#include "log.h"

struct cmd_results *cmd_unlock(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "unlock", EXPECTED_EQUAL_TO, 0))) {
		return error;
	}

	if (server.session_lock.lock) {
		sway_log(SWAY_INFO, "Session unlock requested via command");
		sway_session_lock_unlock(server.session_lock.lock);
		return cmd_results_new(CMD_SUCCESS, "Session unlocked");
	}

	return cmd_results_new(CMD_SUCCESS, "Session is not locked");
}
