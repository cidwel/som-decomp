.setcpu "65816"
.segment "CODE"
.org $5B86
map_control_0e5b86:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
