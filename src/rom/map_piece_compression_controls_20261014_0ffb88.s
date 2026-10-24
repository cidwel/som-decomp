.setcpu "65816"
.segment "CODE"
.org $FB88
map_control_0ffb88:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E1 ; previous-row copy count
