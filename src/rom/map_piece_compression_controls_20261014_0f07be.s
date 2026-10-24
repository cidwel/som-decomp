.setcpu "65816"
.segment "CODE"
.org $07BE
map_control_0f07be:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
