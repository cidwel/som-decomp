.setcpu "65816"
.segment "CODE"
.org $5B1C
map_control_0f5b1c:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
