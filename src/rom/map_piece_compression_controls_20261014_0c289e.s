.setcpu "65816"
.segment "CODE"
.org $289E
map_control_0c289e:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
