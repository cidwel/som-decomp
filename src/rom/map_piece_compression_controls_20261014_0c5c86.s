.setcpu "65816"
.segment "CODE"
.org $5C86
map_control_0c5c86:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
