.setcpu "65816"
.segment "CODE"
.org $B14D
map_control_0eb14d:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
