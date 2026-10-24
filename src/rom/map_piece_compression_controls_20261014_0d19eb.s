.setcpu "65816"
.segment "CODE"
.org $19EB
map_control_0d19eb:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
