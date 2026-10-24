.setcpu "65816"
.segment "CODE"
.org $E652
map_control_0de652:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E2 ; previous-row copy count
