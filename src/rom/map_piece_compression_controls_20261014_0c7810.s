.setcpu "65816"
.segment "CODE"
.org $7810
map_control_0c7810:
    .byte $D9 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
