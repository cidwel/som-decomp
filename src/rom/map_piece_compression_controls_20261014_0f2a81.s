.setcpu "65816"
.segment "CODE"
.org $2A81
map_control_0f2a81:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
