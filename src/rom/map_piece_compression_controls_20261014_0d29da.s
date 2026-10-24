.setcpu "65816"
.segment "CODE"
.org $29DA
map_control_0d29da:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
