.setcpu "65816"
.segment "CODE"
.org $8A7C
map_control_0d8a7c:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
