.setcpu "65816"
.segment "CODE"
.org $C1E9
map_control_0ec1e9:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
