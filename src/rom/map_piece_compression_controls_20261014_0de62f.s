.setcpu "65816"
.segment "CODE"
.org $E62F
map_control_0de62f:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
