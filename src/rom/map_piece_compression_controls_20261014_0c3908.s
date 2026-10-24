.setcpu "65816"
.segment "CODE"
.org $3908
map_control_0c3908:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
