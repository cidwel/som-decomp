.setcpu "65816"
.segment "CODE"
.org $ABBD
map_control_0dabbd:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
