.setcpu "65816"
.segment "CODE"
.org $F843
map_control_0ff843:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
