.setcpu "65816"
.segment "CODE"
.org $EE06
map_control_0eee06:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
