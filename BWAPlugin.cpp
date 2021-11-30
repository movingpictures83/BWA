#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BWAPlugin.h"

void BWAPlugin::input(std::string file) {
 inputfile = file;
}

void BWAPlugin::run() {
   
}

void BWAPlugin::output(std::string file) {
 // spades.py -o 02_BWA -1 $1 -2 $2 --careful
 // assembly-stats -t ./All_assemblies/*.fasta > ./All_assemblies/00_Metrics_all_assemblies.txt
	std::string command = "bwa index "+inputfile+" "+file;
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<BWAPlugin> BWAPluginProxy = PluginProxy<BWAPlugin>("BWA", PluginManager::getInstance());
