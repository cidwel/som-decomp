.setcpu "65816"
.segment "CODE"
.org $9CFD
map_control_0e9cfd:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
