.setcpu "65816"
.segment "CODE"
.org $C2DE
map_control_0dc2de:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
