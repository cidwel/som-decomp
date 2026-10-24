.setcpu "65816"
.segment "CODE"
.org $9B62
map_control_0e9b62:
    .byte $E0 ; previous-row copy escape
    .byte $BD ; row-distance/count
    .byte $E1 ; previous-row copy count
