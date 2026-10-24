.setcpu "65816"
.segment "CODE"
.org $F1E3
map_control_0cf1e3:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
