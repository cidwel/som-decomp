.setcpu "65816"
.segment "CODE"
.org $2232
map_control_0e2232:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
