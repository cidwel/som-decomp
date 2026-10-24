.setcpu "65816"
.segment "CODE"
.org $01C5
map_control_0f01c5:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
