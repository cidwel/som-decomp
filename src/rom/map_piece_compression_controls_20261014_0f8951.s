.setcpu "65816"
.segment "CODE"
.org $8951
map_control_0f8951:
    .byte $C2 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
