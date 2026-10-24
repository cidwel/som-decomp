.setcpu "65816"
.segment "CODE"
.org $C052
map_control_0dc052:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
