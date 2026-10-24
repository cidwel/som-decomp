.setcpu "65816"
.segment "CODE"
.org $C1F1
map_control_0ec1f1:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
