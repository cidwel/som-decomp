.setcpu "65816"
.segment "CODE"
.org $AE2D
map_control_0dae2d:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
