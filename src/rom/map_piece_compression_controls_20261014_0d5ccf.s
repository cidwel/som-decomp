.setcpu "65816"
.segment "CODE"
.org $5CCF
map_control_0d5ccf:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E3 ; previous-row copy count
