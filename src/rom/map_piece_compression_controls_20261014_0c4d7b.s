.setcpu "65816"
.segment "CODE"
.org $4D7B
map_control_0c4d7b:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
