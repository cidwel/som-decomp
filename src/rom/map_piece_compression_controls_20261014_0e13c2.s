.setcpu "65816"
.segment "CODE"
.org $13C2
map_control_0e13c2:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
