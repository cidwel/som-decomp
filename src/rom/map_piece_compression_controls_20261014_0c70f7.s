.setcpu "65816"
.segment "CODE"
.org $70F7
map_control_0c70f7:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
