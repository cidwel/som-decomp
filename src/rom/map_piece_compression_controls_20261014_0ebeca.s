.setcpu "65816"
.segment "CODE"
.org $BECA
map_control_0ebeca:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
