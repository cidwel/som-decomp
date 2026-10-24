.setcpu "65816"
.segment "CODE"
.org $29AF
map_control_0e29af:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
