.setcpu "65816"
.segment "CODE"
.org $5AEE
map_control_0f5aee:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
