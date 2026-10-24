.setcpu "65816"
.segment "CODE"
.org $72E9
map_control_0e72e9:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
