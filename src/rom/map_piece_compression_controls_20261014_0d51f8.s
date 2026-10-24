.setcpu "65816"
.segment "CODE"
.org $51F8
map_control_0d51f8:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
