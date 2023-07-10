static int64_t get_update_timediff(int first_call)
{
	int64_t retval = 0;
	static int64_t last_time = 0;

	/* on first call, simply set the last time and return */
	if(first_call) {
		last_time = get_time_ms();
	} else {
		int64_t this_time = get_time_ms();
		retval = this_time - last_time;

		/* do not update last_time if interval was too short */
		if(retval < 0 || retval >= UPDATE_SPEED_MS) {
			last_time = this_time;
		}
	}

	return retval;
}
