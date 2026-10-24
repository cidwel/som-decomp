.setcpu "65816"
.segment "CODE"
.org $FF31
map_control_0dff31:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
