.setcpu "65816"
.segment "CODE"
.org $D625
map_control_0fd625:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
