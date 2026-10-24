.setcpu "65816"
.segment "CODE"
.org $8543
map_control_0c8543:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
