.setcpu "65816"
.segment "CODE"
.org $497F
map_control_0c497f:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
