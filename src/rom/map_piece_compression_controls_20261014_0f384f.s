.setcpu "65816"
.segment "CODE"
.org $384F
map_control_0f384f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
