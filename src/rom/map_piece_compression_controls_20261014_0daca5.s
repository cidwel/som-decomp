.setcpu "65816"
.segment "CODE"
.org $ACA5
map_control_0daca5:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
