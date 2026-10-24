.setcpu "65816"
.segment "CODE"
.org $749F
map_control_0f749f:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
