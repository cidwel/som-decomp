.setcpu "65816"
.segment "CODE"
.org $6A9F
map_control_0d6a9f:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
