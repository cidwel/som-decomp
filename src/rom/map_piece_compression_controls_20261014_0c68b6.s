.setcpu "65816"
.segment "CODE"
.org $68B6
map_control_0c68b6:
    .byte $DF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
