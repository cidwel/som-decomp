.setcpu "65816"
.segment "CODE"
.org $853C
map_control_0e853c:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4B ; distance low bit/count
