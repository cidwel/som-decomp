.setcpu "65816"
.segment "CODE"
.org $09EB
map_control_0f09eb:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
