.setcpu "65816"
.segment "CODE"
.org $CD22
map_control_0fcd22:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
