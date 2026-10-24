.setcpu "65816"
.segment "CODE"
.org $755F
map_control_0c755f:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
