.setcpu "65816"
.segment "CODE"
.org $5E9D
map_control_0f5e9d:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
