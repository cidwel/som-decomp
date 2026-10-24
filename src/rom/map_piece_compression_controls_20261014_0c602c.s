.setcpu "65816"
.segment "CODE"
.org $602C
map_control_0c602c:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
