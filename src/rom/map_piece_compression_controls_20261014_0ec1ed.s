.setcpu "65816"
.segment "CODE"
.org $C1ED
map_control_0ec1ed:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
