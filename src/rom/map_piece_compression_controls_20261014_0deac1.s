.setcpu "65816"
.segment "CODE"
.org $EAC1
map_control_0deac1:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
