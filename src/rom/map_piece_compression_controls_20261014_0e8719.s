.setcpu "65816"
.segment "CODE"
.org $8719
map_control_0e8719:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
