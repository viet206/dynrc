--[[
	Script Build Lua
]]--

local msg = [[
	Script Build
	Usage : %s opt

	Option :
	-b : build
]]

local command = "%s %s %s %s"
local cc = "gcc"
local cf = "-Werror -Wall -Wextra -shared -fPIC"
local src = "../src/compat.c -I../src -I../src/hal ../src/hal/hal_libc.c"
local target = "-o libdrc.so"

if arg[1] == nil then
	print(string.format(msg,arg[0]))
	os.exit(1)
end

if arg[1] == "-b" then
	os.execute(string.format(command,cc,cf,src,target))
else
	print("Option Not found")
end
