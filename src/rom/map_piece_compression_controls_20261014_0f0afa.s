.setcpu "65816"
.segment "CODE"
.org $0AFA
map_control_0f0afa:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
