.setcpu "65816"
.segment "CODE"
.org $27F1
map_control_0e27f1:
    .byte $C7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
