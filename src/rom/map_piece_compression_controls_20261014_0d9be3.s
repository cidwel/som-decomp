.setcpu "65816"
.segment "CODE"
.org $9BE3
map_control_0d9be3:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
