.setcpu "65816"
.segment "CODE"
.org $8BC1
map_control_0d8bc1:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
