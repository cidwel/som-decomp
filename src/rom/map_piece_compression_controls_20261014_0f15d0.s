.setcpu "65816"
.segment "CODE"
.org $15D0
map_control_0f15d0:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
