.setcpu "65816"
.segment "CODE"
.org $3000
map_control_0e3000:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E3 ; previous-row copy count
