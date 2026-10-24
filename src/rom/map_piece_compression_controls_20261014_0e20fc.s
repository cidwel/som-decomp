.setcpu "65816"
.segment "CODE"
.org $20FC
map_control_0e20fc:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
