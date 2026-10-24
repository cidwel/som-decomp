.setcpu "65816"
.segment "CODE"
.org $5028
map_control_0f5028:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
