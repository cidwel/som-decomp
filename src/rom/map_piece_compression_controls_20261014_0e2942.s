.setcpu "65816"
.segment "CODE"
.org $2942
map_control_0e2942:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
