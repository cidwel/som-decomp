.setcpu "65816"
.segment "CODE"
.org $5F69
map_control_0c5f69:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
