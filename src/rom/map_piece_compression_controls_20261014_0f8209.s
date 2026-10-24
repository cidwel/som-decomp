.setcpu "65816"
.segment "CODE"
.org $8209
map_control_0f8209:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
