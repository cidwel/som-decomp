.setcpu "65816"
.segment "CODE"
.org $34E8
map_control_0f34e8:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
