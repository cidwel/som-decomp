.setcpu "65816"
.segment "CODE"
.org $9807
map_control_0e9807:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
