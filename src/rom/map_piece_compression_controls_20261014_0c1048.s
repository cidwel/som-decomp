.setcpu "65816"
.segment "CODE"
.org $1048
map_control_0c1048:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
