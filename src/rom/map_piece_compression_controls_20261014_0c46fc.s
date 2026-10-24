.setcpu "65816"
.segment "CODE"
.org $46FC
map_control_0c46fc:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
