.setcpu "65816"
.segment "CODE"
.org $784C
map_control_0e784c:
    .byte $E2 ; previous-row copy count
    .byte $C9 ; same-value copy count/distance
