.setcpu "65816"
.segment "CODE"
.org $255D
map_control_0d255d:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
