.setcpu "65816"
.segment "CODE"
.org $9DB1
map_control_0e9db1:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
