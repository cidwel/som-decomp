.setcpu "65816"
.segment "CODE"
.org $5DA0
map_control_0c5da0:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
