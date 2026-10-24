.setcpu "65816"
.segment "CODE"
.org $8CB9
map_control_0f8cb9:
    .byte $C9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
