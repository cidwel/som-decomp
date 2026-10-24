.setcpu "65816"
.segment "CODE"
.org $5795
map_control_0f5795:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
