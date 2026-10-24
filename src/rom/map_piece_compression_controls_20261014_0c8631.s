.setcpu "65816"
.segment "CODE"
.org $8631
map_control_0c8631:
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E7 ; previous-row copy count
