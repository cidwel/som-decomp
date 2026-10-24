.setcpu "65816"
.segment "CODE"
.org $64BE
map_control_0f64be:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
