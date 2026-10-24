.setcpu "65816"
.segment "CODE"
.org $9E36
map_control_0f9e36:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
