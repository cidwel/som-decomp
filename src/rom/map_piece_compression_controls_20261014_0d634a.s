.setcpu "65816"
.segment "CODE"
.org $634A
map_control_0d634a:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
