.setcpu "65816"
.segment "CODE"
.org $6B90
map_control_0c6b90:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
