.setcpu "65816"
.segment "CODE"
.org $2F31
map_control_0f2f31:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
