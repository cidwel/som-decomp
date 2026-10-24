.setcpu "65816"
.segment "CODE"
.org $6478
map_control_0d6478:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
