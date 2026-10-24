.setcpu "65816"
.segment "CODE"
.org $19EB
map_control_0f19eb:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
