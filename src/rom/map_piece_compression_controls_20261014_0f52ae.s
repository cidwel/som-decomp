.setcpu "65816"
.segment "CODE"
.org $52AE
map_control_0f52ae:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
