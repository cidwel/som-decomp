.setcpu "65816"
.segment "CODE"
.org $F9F9
map_control_0df9f9:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
