.setcpu "65816"
.segment "CODE"
.org $25B7
map_control_0f25b7:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
