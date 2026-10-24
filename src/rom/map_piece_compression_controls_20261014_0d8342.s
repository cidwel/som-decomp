.setcpu "65816"
.segment "CODE"
.org $8342
map_control_0d8342:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
