.setcpu "65816"
.segment "CODE"
.org $D6AC
map_control_0fd6ac:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E1 ; previous-row copy count
