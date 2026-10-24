.setcpu "65816"
.segment "CODE"
.org $0880
map_control_0f0880:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
