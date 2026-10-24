.setcpu "65816"
.segment "CODE"
.org $B039
map_control_0eb039:
    .byte $E2 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
