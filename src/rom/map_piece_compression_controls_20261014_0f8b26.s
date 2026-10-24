.setcpu "65816"
.segment "CODE"
.org $8B26
map_control_0f8b26:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
