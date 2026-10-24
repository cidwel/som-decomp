.setcpu "65816"
.segment "CODE"
.org $D3BA
map_control_0ed3ba:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
