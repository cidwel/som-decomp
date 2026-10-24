.setcpu "65816"
.segment "CODE"
.org $50BD
map_control_0d50bd:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
