.setcpu "65816"
.segment "CODE"
.org $5B5C
map_control_0f5b5c:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
