.setcpu "65816"
.segment "CODE"
.org $64A7
map_control_0f64a7:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
