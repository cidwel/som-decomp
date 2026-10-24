.setcpu "65816"
.segment "CODE"
.org $6873
map_control_0e6873:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
