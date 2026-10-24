.setcpu "65816"
.segment "CODE"
.org $68CE
map_control_0e68ce:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
