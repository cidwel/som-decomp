.setcpu "65816"
.segment "CODE"
.org $7BDE
map_control_0c7bde:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
