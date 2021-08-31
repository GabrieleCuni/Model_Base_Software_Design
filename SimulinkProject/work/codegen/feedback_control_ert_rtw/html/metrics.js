function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["ceil"] = {file: "/usr/local/MATLAB/R2020b/polyspace/verifier/cxx/include/include-libc/bits/mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "/usr/local/MATLAB/R2020b/polyspace/verifier/cxx/include/include-libc/bits/mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["feedback_control.c:feedback_co_exit_atomic_ECHO_UP"] = {file: "/home/gabriele/Desktop/Data_Science_and_Engineering/Second_Year/Second_Semester/Model_Base_Software_Design/Simulink/MBSD_Assignment_Gabriele_Cuni/work/codegen/feedback_control_ert_rtw/feedback_control.c",
	stack: 12,
	stackTotal: 20};
	 this.metricsArray.fcn["feedback_control_initialize"] = {file: "/home/gabriele/Desktop/Data_Science_and_Engineering/Second_Year/Second_Semester/Model_Base_Software_Design/Simulink/MBSD_Assignment_Gabriele_Cuni/work/codegen/feedback_control_ert_rtw/feedback_control.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["feedback_control_step"] = {file: "/home/gabriele/Desktop/Data_Science_and_Engineering/Second_Year/Second_Semester/Model_Base_Software_Design/Simulink/MBSD_Assignment_Gabriele_Cuni/work/codegen/feedback_control_ert_rtw/feedback_control.c",
	stack: 4,
	stackTotal: 24};
	 this.metricsArray.fcn["feedback_control_terminate"] = {file: "/home/gabriele/Desktop/Data_Science_and_Engineering/Second_Year/Second_Semester/Model_Base_Software_Design/Simulink/MBSD_Assignment_Gabriele_Cuni/work/codegen/feedback_control_ert_rtw/feedback_control.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "/usr/local/MATLAB/R2020b/polyspace/verifier/cxx/include/include-libc/bits/mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "/usr/local/MATLAB/R2020b/polyspace/verifier/cxx/include/include-libc/string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_roundd"] = {file: "/home/gabriele/Desktop/Data_Science_and_Engineering/Second_Year/Second_Semester/Model_Base_Software_Design/Simulink/MBSD_Assignment_Gabriele_Cuni/work/codegen/feedback_control_ert_rtw/feedback_control.c",
	stack: 8,
	stackTotal: 8};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="feedback_control_metrics.html">Global Memory: 0(bytes) Maximum Stack: 12(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
