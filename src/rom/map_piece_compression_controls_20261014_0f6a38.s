.setcpu "65816"
.segment "CODE"
.org $6A38
map_control_0f6a38:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
