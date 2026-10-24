.setcpu "65816"
.segment "CODE"
.org $8FDD
map_control_0c8fdd:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $E4 ; previous-row copy count
