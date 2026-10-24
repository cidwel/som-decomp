.setcpu "65816"
.segment "CODE"
.org $2B39
map_control_0e2b39:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
