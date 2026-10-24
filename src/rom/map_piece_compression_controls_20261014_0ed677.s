.setcpu "65816"
.segment "CODE"
.org $D677
map_control_0ed677:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
