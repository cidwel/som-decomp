.setcpu "65816"
.segment "CODE"
.org $37A7
map_control_0f37a7:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
