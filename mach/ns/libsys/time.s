.define _time
.extern _time
.text
_time:
enter[], 12
addr -12(fp),tos
jsr @_ftime
adjspd -4
cmpqd 0,8(fp)
beq I0013
movd -12(fp),0(8(fp))
I0013:
movd -12(fp),r4
exit []
ret 0
