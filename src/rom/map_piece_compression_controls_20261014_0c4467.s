.setcpu "65816"
.segment "CODE"
.org $4467
map_control_0c4467:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
