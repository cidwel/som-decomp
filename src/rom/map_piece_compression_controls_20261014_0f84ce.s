.setcpu "65816"
.segment "CODE"
.org $84CE
map_control_0f84ce:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
