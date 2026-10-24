.setcpu "65816"
.segment "CODE"
.org $14FA
map_control_0c14fa:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
