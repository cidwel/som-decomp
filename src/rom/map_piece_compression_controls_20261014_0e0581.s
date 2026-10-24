.setcpu "65816"
.segment "CODE"
.org $0581
map_control_0e0581:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
