.setcpu "65816"
.segment "CODE"
.org $5FF6
map_control_0f5ff6:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
