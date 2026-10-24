.setcpu "65816"
.segment "CODE"
.org $0668
map_control_0f0668:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
