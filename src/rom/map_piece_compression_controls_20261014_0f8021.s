.setcpu "65816"
.segment "CODE"
.org $8021
map_control_0f8021:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
