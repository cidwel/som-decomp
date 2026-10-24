.setcpu "65816"
.segment "CODE"
.org $C7C4
map_control_0dc7c4:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
