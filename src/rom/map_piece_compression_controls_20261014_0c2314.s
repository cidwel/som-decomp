.setcpu "65816"
.segment "CODE"
.org $2314
map_control_0c2314:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
