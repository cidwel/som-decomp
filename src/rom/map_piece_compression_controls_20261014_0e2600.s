.setcpu "65816"
.segment "CODE"
.org $2600
map_control_0e2600:
    .byte $F5 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
