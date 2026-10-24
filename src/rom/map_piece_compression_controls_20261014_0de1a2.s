.setcpu "65816"
.segment "CODE"
.org $E1A2
map_control_0de1a2:
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
