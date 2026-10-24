.setcpu "65816"
.segment "CODE"
.org $DAAD
map_control_0fdaad:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
