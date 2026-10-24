.setcpu "65816"
.segment "CODE"
.org $4AF6
map_control_0f4af6:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
