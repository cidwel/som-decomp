.setcpu "65816"
.segment "CODE"
.org $6EB3
map_control_0d6eb3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
