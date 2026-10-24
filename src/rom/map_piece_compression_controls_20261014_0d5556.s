.setcpu "65816"
.segment "CODE"
.org $5556
map_control_0d5556:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
