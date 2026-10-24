.setcpu "65816"
.segment "CODE"
.org $0DF6
map_control_0d0df6:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
