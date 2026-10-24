.setcpu "65816"
.segment "CODE"
.org $08EE
map_control_0f08ee:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
