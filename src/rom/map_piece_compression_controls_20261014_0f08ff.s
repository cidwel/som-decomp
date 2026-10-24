.setcpu "65816"
.segment "CODE"
.org $08FF
map_control_0f08ff:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
