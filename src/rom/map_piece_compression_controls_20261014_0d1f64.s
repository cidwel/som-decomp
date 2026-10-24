.setcpu "65816"
.segment "CODE"
.org $1F64
map_control_0d1f64:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
