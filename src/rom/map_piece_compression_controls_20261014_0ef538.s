.setcpu "65816"
.segment "CODE"
.org $F538
map_control_0ef538:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
