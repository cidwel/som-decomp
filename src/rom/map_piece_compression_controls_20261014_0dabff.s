.setcpu "65816"
.segment "CODE"
.org $ABFF
map_control_0dabff:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
