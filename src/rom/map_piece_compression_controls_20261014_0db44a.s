.setcpu "65816"
.segment "CODE"
.org $B44A
map_control_0db44a:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
