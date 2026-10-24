.setcpu "65816"
.segment "CODE"
.org $7739
map_control_0f7739:
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
