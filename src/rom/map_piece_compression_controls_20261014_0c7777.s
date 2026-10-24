.setcpu "65816"
.segment "CODE"
.org $7777
map_control_0c7777:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
