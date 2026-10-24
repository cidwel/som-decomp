.setcpu "65816"
.segment "CODE"
.org $D1C6
map_control_0ed1c6:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
