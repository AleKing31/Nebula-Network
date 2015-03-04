
l = Dynamic("nebula_plugin_net1")

l.inc_dirs.append("/usr/include/freetype2")

l.require("galaxy_std", whole=True)
l.require("galaxy_log", whole=True)
l.require("galaxy_console", whole=True)
l.require("nebula_core", whole=True)

l.make()



