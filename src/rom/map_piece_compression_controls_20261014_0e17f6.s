.setcpu "65816"
.segment "CODE"
.org $17F6
map_control_0e17f6:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
