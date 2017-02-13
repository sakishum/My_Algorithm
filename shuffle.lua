#! usr/local/bin/lua

--[[
	Another useful algorithm I found on Wikipedia is a shuffle algorithm for tables. 
	This is handy for situations where you have a collection of data (eg. a pack of cards) 
	and you want to present them randomly.
]]--

local seed = math.randomseed
local time = os.time
local random = math.random

local function shuffle(t) 
	local n = #t
	seed(time()) 
	while n >= 2 do
    	-- n is now the last pertinent index
    	local k = random(n) -- 1 <= k <= n
    	-- Quick swap
    	t[n], t[k] = t[k], t[n]
    	n = n - 1
  	end
  return t
end

cards = { "Ace", "King", "Queen", "Jack", 10, 9, 8, 7, 6, 5, 4, 3, 2 }

shuffle(cards)
for k, v in ipairs (cards) do
  print (v)
end -- for

