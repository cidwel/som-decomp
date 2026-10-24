.setcpu "65816"
.segment "CODE"
.org $EAEE
map_control_0eeaee:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
