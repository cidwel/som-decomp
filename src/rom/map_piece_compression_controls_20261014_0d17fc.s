.setcpu "65816"
.segment "CODE"
.org $17FC
map_control_0d17fc:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
