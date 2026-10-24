.setcpu "65816"
.segment "CODE"
.org $C001
map_control_0ec001:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
