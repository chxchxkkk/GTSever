#ifndef GT_MODULE_WRAPPER_H_
#define GT_MODULE_WRAPPER_H_


#include "GTIOCP/GTIOCP.h"
#include "GTSelect/GT_Select.h"
#include "GTIOCP/GT_Definition.h"
#include "GTUtlity/GT_Util_GlogWrapper.h"

#include <string>

namespace GT {
    namespace   MODULE {

#define DEFAULT_CFG_PATH ".//GTServer.cfg"
		enum MODULE_TYPE {
			GT_IOCP,
			GT_Select
		};

        class GT_Module_Wrapper
        {
		public:
			~GT_Module_Wrapper();
			static GT_Module_Wrapper& GetInstance();

			void SetModuleType(MODULE_TYPE);
			void InitLogService(std::string cfg_pth = DEFAULT_CFG_PATH);
			bool Initialize(std::string cfg_path);
			bool StartGTService();
			void ExitGTService();

			static void ReadEventCallback(PULONG_PTR, const char*, int);
			static void WriteEventCallBack(PULONG_PTR, const char*, int);

		private:
            GT_Module_Wrapper();

		private:
			bool is_module_initted_;
			MODULE_TYPE module_type_;
        };
    }
}

#endif