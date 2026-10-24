.setcpu "65816"
.segment "CODE"
.org $EE03
map_control_0dee03:
    .byte $C4 ; same-value copy count/distance
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
