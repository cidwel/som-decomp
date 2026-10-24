.setcpu "65816"
.segment "CODE"
.org $20CE
map_control_0f20ce:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
