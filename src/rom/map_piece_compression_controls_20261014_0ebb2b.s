.setcpu "65816"
.segment "CODE"
.org $BB2B
map_control_0ebb2b:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
