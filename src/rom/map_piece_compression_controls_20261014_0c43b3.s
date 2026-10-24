.setcpu "65816"
.segment "CODE"
.org $43B3
map_control_0c43b3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E3 ; previous-row copy count
