.setcpu "65816"
.segment "CODE"
.org $DE37
map_control_0ede37:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
