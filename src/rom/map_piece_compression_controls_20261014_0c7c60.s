.setcpu "65816"
.segment "CODE"
.org $7C60
map_control_0c7c60:
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
