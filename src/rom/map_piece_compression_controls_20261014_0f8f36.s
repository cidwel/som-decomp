.setcpu "65816"
.segment "CODE"
.org $8F36
map_control_0f8f36:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
