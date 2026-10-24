.setcpu "65816"
.segment "CODE"
.org $C958
map_control_0dc958:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
