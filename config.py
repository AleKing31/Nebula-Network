l = Static("nebula_net")

l.inc_dirs.append("/usr/include/freetype2")

l.require("galaxy_std")
l.require("galaxy_log")
l.require("galaxy_net")
l.require("nebula_core")

l.make()

