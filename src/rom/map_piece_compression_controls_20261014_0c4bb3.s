.setcpu "65816"
.segment "CODE"
.org $4BB3
map_control_0c4bb3:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
