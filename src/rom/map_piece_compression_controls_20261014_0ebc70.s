.setcpu "65816"
.segment "CODE"
.org $BC70
map_control_0ebc70:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
