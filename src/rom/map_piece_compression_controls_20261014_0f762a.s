.setcpu "65816"
.segment "CODE"
.org $762A
map_control_0f762a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
