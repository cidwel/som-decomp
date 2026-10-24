.setcpu "65816"
.segment "CODE"
.org $55CD
map_control_0c55cd:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
