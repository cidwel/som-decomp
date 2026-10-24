.setcpu "65816"
.segment "CODE"
.org $14AD
map_control_0f14ad:
    .byte $C9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
