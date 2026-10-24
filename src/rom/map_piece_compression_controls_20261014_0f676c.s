.setcpu "65816"
.segment "CODE"
.org $676C
map_control_0f676c:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
