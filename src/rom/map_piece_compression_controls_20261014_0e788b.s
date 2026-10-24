.setcpu "65816"
.segment "CODE"
.org $788B
map_control_0e788b:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
