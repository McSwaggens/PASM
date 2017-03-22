
// DEFAULT_SCRIPT_LOCATION

#if defined(__WIN32__) || defined(__WIN64__)

	#define DEFAULT_SCRIPT_LOCATION "/User/daniel/Documents/Scripts/test.p"

#elif defined(__APPLE__)

	#define DEFAULT_SCRIPT_LOCATION "/User/daniel/Documents/Scripts/test.p"

#elif defined(__linux__) || defined(__unix__)

	#define DEFAULT_SCRIPT_LOCATION "/home/daniel/Documents/Scripts/test.p"

#endif




#define SHOW_DEBUG_INFORMATION true

#define MEMORY_EXCEPTION 20