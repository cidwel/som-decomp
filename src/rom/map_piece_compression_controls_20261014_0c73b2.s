.setcpu "65816"
.segment "CODE"
.org $73B2
map_control_0c73b2:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E3 ; previous-row copy count
