.setcpu "65816"
.segment "CODE"
.org $250C
map_control_0f250c:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
