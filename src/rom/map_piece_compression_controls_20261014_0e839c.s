.setcpu "65816"
.segment "CODE"
.org $839C
map_control_0e839c:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
