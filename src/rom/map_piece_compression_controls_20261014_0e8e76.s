.setcpu "65816"
.segment "CODE"
.org $8E76
map_control_0e8e76:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E5 ; previous-row copy count
