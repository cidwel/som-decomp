.setcpu "65816"
.segment "CODE"
.org $B77A
map_control_0fb77a:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
