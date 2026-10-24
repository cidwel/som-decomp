.setcpu "65816"
.segment "CODE"
.org $C1DD
map_control_0ec1dd:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
