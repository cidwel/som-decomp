.setcpu "65816"
.segment "CODE"
.org $64A2
map_control_0f64a2:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
