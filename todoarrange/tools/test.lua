function encode_long(l)
    local a = l/(0x100*0x100*0x100)%0x100
    local b = l/(0x100*0x100)%0x100
    local c = l/(0x100)%0x100
    local d = l%0x100
    print("a ".. a .. "b " .. b.. "c " .. c .. "d" .. d)
	a = math.modf(a, 1)
	b = math.modf(b, 1)
	c = math.modf(c, 1)
	d = math.modf(d, 1)
	print("a ".. a .. "b " .. b.. "c " .. c .. "d" .. d)

    return string.char(a,b,c,d)
end


function encode_short(s)
    local a = s/(0x100)%0x100
    local b = s%0x100
    a = math.modf(a, 1)
    b = math.modf(b, 1)
    return string.char(a, b)
end

function encode_byte(b)
    local a = b%0x100
    a = math.modf(a, 1)
    return string.char(a)
end



function decode_long(s, i)
    if i + 4 > string.len(s) + 1 then
        return nil
    end
    local a = string.byte(s,i,i)
    local b = string.byte(s,i+1,i+1)
    local c = string.byte(s,i+2,i+2)
    local d = string.byte(s,i+3,i+3)
    print(a,b,c,d)
    return a*0x100*0x100*0x100 + b*0x100*0x100 + c*0x100 + d
end

function decode_short(s, i)
    if i + 2 > string.len(s)+1 then
        return nil
    end
    local a = string.byte(s,i,i)
    local b = string.byte(s,i+1,i+1)
    return a*0x100 + b
end

function decode_byte(s, i)
    if i + 1 > string.len(s)+1 then
        return nil
    end
    local a = string.byte(s,i,i)
    return a
end



s = encode_long(99)
d = decode_long(s, 1)
print("d " .. d)


s = encode_short(99)
d = decode_short(s, 1)
print("d " .. d)


