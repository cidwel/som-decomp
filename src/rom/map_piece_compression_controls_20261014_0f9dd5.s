.setcpu "65816"
.segment "CODE"
.org $9DD5
map_control_0f9dd5:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
