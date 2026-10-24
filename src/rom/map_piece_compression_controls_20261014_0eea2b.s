.setcpu "65816"
.segment "CODE"
.org $EA2B
map_control_0eea2b:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
