.setcpu "65816"
.segment "CODE"
.org $194D
map_control_0e194d:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
