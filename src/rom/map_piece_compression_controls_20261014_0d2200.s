.setcpu "65816"
.segment "CODE"
.org $2200
map_control_0d2200:
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
