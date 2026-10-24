.setcpu "65816"
.segment "CODE"
.org $9AE4
map_control_0d9ae4:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
