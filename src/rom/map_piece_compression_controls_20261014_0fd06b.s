.setcpu "65816"
.segment "CODE"
.org $D06B
map_control_0fd06b:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
