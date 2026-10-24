.setcpu "65816"
.segment "CODE"
.org $3751
map_control_0f3751:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
