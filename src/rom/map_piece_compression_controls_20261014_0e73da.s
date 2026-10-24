.setcpu "65816"
.segment "CODE"
.org $73DA
map_control_0e73da:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
