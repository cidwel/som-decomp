.setcpu "65816"
.segment "CODE"
.org $B021
map_control_0eb021:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
