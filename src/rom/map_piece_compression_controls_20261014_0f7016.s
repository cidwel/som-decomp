.setcpu "65816"
.segment "CODE"
.org $7016
map_control_0f7016:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
