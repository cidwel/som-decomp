.setcpu "65816"
.segment "CODE"
.org $4450
map_control_0c4450:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
