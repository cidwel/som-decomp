.setcpu "65816"
.segment "CODE"
.org $22AA
map_control_0f22aa:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
