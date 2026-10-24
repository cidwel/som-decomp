.setcpu "65816"
.segment "CODE"
.org $5786
map_control_0f5786:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
