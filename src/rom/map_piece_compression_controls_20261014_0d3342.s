.setcpu "65816"
.segment "CODE"
.org $3342
map_control_0d3342:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
