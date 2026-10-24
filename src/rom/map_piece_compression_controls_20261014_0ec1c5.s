.setcpu "65816"
.segment "CODE"
.org $C1C5
map_control_0ec1c5:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
