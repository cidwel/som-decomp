.setcpu "65816"
.segment "CODE"
.org $DAEF
map_control_0fdaef:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
