.setcpu "65816"
.segment "CODE"
.org $8B3F
map_control_0c8b3f:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
