.setcpu "65816"
.segment "CODE"
.org $7083
map_control_0d7083:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
