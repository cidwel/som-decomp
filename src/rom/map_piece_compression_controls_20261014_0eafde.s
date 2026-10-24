.setcpu "65816"
.segment "CODE"
.org $AFDE
map_control_0eafde:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
