.setcpu "65816"
.segment "CODE"
.org $D136
map_control_0fd136:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
