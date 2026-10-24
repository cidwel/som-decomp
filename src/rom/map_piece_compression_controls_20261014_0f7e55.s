.setcpu "65816"
.segment "CODE"
.org $7E55
map_control_0f7e55:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
