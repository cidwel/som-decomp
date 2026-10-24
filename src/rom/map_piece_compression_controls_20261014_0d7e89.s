.setcpu "65816"
.segment "CODE"
.org $7E89
map_control_0d7e89:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
