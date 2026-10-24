.setcpu "65816"
.segment "CODE"
.org $D430
map_control_0fd430:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
