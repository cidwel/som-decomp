.setcpu "65816"
.segment "CODE"
.org $BAAE
map_control_0dbaae:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
