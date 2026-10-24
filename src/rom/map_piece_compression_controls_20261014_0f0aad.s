.setcpu "65816"
.segment "CODE"
.org $0AAD
map_control_0f0aad:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
