.setcpu "65816"
.segment "CODE"
.org $4BB6
map_control_0d4bb6:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
