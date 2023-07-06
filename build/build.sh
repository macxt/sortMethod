#!/bin/bash
## Automatically execute current directory Makefile with some specified parameters.
## And move compile result file to package folder created if not exists under the upper path. 

current_dir=$(pwd)

package_dir=${current_dir}/../package

bin_dir=${package_dir}/bin

lib_dir=${package_dir}/lib

config_dir=${package_dir}/config

#parse scripts parameters with getopts built-in shell tools
#b:benchmark, cpp compile standard(11,14,17,20)
#c:clean
#s:make stage
#d:debug
#v:version print compile detail
MakeStage=a
CmdLineParam=
while getopts 'b:cs:dv' opt;
do
    case $opt in
        b)
          CmdLineParam+="csv=$OPTARG "
          ;;
        c)
          make clean
          ;;
        s)
          MakeStage=$OPTARG
          ;;
        d)
          CmdLineParam+="debug=y "
          ;;
        v)
          CmdLineParam+="detail=y "
          ;;
    esac
done

#define shell function to excute makefile
#the value of IsLibFile variable is "-shared" if compile target is library file.
#make_otherlib()
#{
#    make -f Makefile ${CmdLineParam} IsLibFile="-shared"
#    if [[ $? != 0 ]];then
#        echo "Execute makefile to generate target library file error."
#        exit 1;
#    fi
#}

#default IsLibFile variable is empty if target is executable file.
make_all()
{
    #make_otherfunc
    #make_otherlib
    make -f Makefile ${CmdLineParam} IsLibFile="" TargetExeFile=sort_exe
    if [[ $? != 0 ]];then
        echo "Execute makefile to generate target file error."
        exit 1;
    fi
}

#execute different compile procedure dependent on make stage.
case ${MakeStage} in
    a)
      make_all
      ;;
#    f)
#      make_otherfunc
#      exit 0
#      ;;
#    l)
#      make_otherlib
#      exit 0
#      ;;
esac

#create package folder under the upper path
if [[ -d ${package_dir} ]]; then
    echo "package folder exists, and delete first before creating."
    rm -rf ${package_dir}
fi

#create bin lib config folder.
mkdir -p ${bin_dir} ${lib_dir} ${config_dir}
if [[ $? != 0 ]]; then
    echo "create bin/lib/config folder error."
    exit 1;
else
    echo "create bin/lib/config folder done."
fi

TargetExeFile=${current_dir}/sort_exe

#move execute file, library file and config file to package directory.
#mv ${ConfigFile} ${config_dir}
#mv ${LibFile} ${lib_dir}
mv ${TargetExeFile} ${bin_dir}

#echo ${lib_dir} > /etc/ld.so.conf.d/xxxx.conf
#ldconfig

echo "Execute Makefile and Compile Finished."
