.setcpu "65816"
.segment "CODE"
.org $1684
map_control_0f1684:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
