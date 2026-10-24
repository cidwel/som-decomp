.setcpu "65816"
.segment "CODE"
.org $E939
map_control_0fe939:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
