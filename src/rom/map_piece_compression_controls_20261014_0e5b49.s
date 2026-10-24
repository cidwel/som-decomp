.setcpu "65816"
.segment "CODE"
.org $5B49
map_control_0e5b49:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E2 ; previous-row copy count
