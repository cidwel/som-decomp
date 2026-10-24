.setcpu "65816"
.segment "CODE"
.org $5895
map_control_0d5895:
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E6 ; previous-row copy count
