.setcpu "65816"
.segment "CODE"
.org $4921
map_control_0f4921:
    .byte $CC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
