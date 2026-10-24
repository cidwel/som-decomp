.setcpu "65816"
.segment "CODE"
.org $5C33
map_control_0e5c33:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
