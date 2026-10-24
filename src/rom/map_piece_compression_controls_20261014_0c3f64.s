.setcpu "65816"
.segment "CODE"
.org $3F64
map_control_0c3f64:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
