.setcpu "65816"
.segment "CODE"
.org $2CCB
map_control_0f2ccb:
    .byte $C7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
