.setcpu "65816"
.segment "CODE"
.org $1026
map_control_0c1026:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
