.setcpu "65816"
.segment "CODE"
.org $278B
map_control_0c278b:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
