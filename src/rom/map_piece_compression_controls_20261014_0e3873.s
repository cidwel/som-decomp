.setcpu "65816"
.segment "CODE"
.org $3873
map_control_0e3873:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
