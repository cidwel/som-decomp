.setcpu "65816"
.segment "CODE"
.org $674D
map_control_0c674d:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
