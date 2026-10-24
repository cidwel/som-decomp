.setcpu "65816"
.segment "CODE"
.org $2F44
map_control_0d2f44:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
