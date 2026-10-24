.setcpu "65816"
.segment "CODE"
.org $79BE
map_control_0c79be:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
