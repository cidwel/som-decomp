.setcpu "65816"
.segment "CODE"
.org $2759
map_control_0f2759:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
