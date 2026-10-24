.setcpu "65816"
.segment "CODE"
.org $8C9D
map_control_0e8c9d:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
