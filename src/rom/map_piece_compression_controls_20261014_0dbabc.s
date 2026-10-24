.setcpu "65816"
.segment "CODE"
.org $BABC
map_control_0dbabc:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
