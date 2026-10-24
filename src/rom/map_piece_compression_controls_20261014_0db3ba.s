.setcpu "65816"
.segment "CODE"
.org $B3BA
map_control_0db3ba:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E1 ; previous-row copy count
