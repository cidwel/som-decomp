.setcpu "65816"
.segment "CODE"
.org $8785
map_control_0c8785:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
