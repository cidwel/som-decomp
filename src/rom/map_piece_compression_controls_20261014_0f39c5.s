.setcpu "65816"
.segment "CODE"
.org $39C5
map_control_0f39c5:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
