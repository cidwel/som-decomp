.setcpu "65816"
.segment "CODE"
.org $2D99
map_control_0e2d99:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
