.setcpu "65816"
.segment "CODE"
.org $43B4
map_control_0f43b4:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
