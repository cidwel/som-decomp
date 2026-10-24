.setcpu "65816"
.segment "CODE"
.org $2CE8
map_control_0f2ce8:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
