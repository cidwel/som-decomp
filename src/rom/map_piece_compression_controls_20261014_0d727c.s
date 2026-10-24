.setcpu "65816"
.segment "CODE"
.org $727C
map_control_0d727c:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
