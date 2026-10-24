.setcpu "65816"
.segment "CODE"
.org $3DD2
map_control_0c3dd2:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
