.setcpu "65816"
.segment "CODE"
.org $4F8C
map_control_0f4f8c:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
