.setcpu "65816"
.segment "CODE"
.org $C269
map_control_0dc269:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
