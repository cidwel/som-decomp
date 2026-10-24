.setcpu "65816"
.segment "CODE"
.org $C5DA
map_control_0dc5da:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
