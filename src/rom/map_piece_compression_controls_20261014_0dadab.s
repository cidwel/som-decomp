.setcpu "65816"
.segment "CODE"
.org $ADAB
map_control_0dadab:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
