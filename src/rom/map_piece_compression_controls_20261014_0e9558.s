.setcpu "65816"
.segment "CODE"
.org $9558
map_control_0e9558:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
