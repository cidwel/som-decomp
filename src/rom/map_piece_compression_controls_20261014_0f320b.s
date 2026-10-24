.setcpu "65816"
.segment "CODE"
.org $320B
map_control_0f320b:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
