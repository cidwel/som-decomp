.setcpu "65816"
.segment "CODE"
.org $2023
map_control_0d2023:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
