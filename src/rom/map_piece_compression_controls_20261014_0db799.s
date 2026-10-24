.setcpu "65816"
.segment "CODE"
.org $B799
map_control_0db799:
    .byte $E1 ; previous-row copy count
