.setcpu "65816"
.segment "CODE"
.org $1076
map_control_0c1076:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
