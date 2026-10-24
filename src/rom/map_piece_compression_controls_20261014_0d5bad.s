.setcpu "65816"
.segment "CODE"
.org $5BAD
map_control_0d5bad:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
