.setcpu "65816"
.segment "CODE"
.org $F618
map_control_0df618:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
