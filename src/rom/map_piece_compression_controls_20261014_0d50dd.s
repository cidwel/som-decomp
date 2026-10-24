.setcpu "65816"
.segment "CODE"
.org $50DD
map_control_0d50dd:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
