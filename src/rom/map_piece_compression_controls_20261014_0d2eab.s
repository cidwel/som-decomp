.setcpu "65816"
.segment "CODE"
.org $2EAB
map_control_0d2eab:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
