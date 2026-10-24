.setcpu "65816"
.segment "CODE"
.org $9404
map_control_0d9404:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
