.setcpu "65816"
.segment "CODE"
.org $0814
map_control_0d0814:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
