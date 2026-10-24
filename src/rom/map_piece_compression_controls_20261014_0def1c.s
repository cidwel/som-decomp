.setcpu "65816"
.segment "CODE"
.org $EF1C
map_control_0def1c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E2 ; previous-row copy count
