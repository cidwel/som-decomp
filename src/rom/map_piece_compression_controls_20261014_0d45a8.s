.setcpu "65816"
.segment "CODE"
.org $45A8
map_control_0d45a8:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
