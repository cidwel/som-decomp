.setcpu "65816"
.segment "CODE"
.org $3312
map_control_0f3312:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
