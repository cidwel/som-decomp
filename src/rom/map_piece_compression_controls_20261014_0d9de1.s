.setcpu "65816"
.segment "CODE"
.org $9DE1
map_control_0d9de1:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
