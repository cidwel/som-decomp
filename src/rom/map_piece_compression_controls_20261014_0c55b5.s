.setcpu "65816"
.segment "CODE"
.org $55B5
map_control_0c55b5:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
