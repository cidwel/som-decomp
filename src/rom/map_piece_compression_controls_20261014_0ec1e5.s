.setcpu "65816"
.segment "CODE"
.org $C1E5
map_control_0ec1e5:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
