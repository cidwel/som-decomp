.setcpu "65816"
.segment "CODE"
.org $4770
map_control_0f4770:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
