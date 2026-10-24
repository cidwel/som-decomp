.setcpu "65816"
.segment "CODE"
.org $7819
map_control_0e7819:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
