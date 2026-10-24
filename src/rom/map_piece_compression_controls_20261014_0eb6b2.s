.setcpu "65816"
.segment "CODE"
.org $B6B2
map_control_0eb6b2:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
