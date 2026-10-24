.setcpu "65816"
.segment "CODE"
.org $D878
map_control_0fd878:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
