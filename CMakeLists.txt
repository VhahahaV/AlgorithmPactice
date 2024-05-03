cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)
project(AlgorithmPractice)

set(MONTHS ${CMAKE_SOURCE_DIR}/code/*)

# 获取所有月份的文件夹
file(GLOB MONTH_FOLDERS ${MONTHS})

# 设定 DAYS 变量
set(DAYS)

foreach (month ${MONTH_FOLDERS})
    if (IS_DIRECTORY ${month})
        message("加入 ${month} 月份的代码")
        # 添加当前月份的所有文件夹到 DAYS 变量
        file(GLOB DAY_FOLDERS ${month}/*)
        list(APPEND DAYS ${DAY_FOLDERS})
    endif ()
endforeach ()

foreach (day ${DAYS})
    if (IS_DIRECTORY ${day})
        message("加入日期为：${day} 的代码")
        add_subdirectory(${day})
    endif ()
endforeach ()