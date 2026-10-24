.setcpu "65816"
.segment "CODE"
.org $E5F2
map_control_0de5f2:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
