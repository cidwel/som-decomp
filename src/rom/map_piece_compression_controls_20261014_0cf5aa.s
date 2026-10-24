.setcpu "65816"
.segment "CODE"
.org $F5AA
map_control_0cf5aa:
    .byte $CD ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
