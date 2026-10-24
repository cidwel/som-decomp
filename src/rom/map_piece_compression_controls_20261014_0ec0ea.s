.setcpu "65816"
.segment "CODE"
.org $C0EA
map_control_0ec0ea:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
