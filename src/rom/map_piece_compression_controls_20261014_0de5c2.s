.setcpu "65816"
.segment "CODE"
.org $E5C2
map_control_0de5c2:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
