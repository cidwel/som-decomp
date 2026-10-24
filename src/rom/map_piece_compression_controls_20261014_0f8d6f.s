.setcpu "65816"
.segment "CODE"
.org $8D6F
map_control_0f8d6f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
