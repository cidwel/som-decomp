.setcpu "65816"
.segment "CODE"
.org $5AC8
map_control_0d5ac8:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
