.setcpu "65816"
.segment "CODE"
.org $8696
map_control_0f8696:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
