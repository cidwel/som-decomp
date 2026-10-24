.setcpu "65816"
.segment "CODE"
.org $C843
map_control_0dc843:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
