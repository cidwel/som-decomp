.setcpu "65816"
.segment "CODE"
.org $8014
map_control_0f8014:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
