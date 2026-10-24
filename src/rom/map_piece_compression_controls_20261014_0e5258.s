.setcpu "65816"
.segment "CODE"
.org $5258
map_control_0e5258:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $67 ; row-distance/count
