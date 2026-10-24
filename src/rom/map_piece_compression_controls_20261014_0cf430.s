.setcpu "65816"
.segment "CODE"
.org $F430
map_control_0cf430:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
