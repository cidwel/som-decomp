.setcpu "65816"
.segment "CODE"
.org $6D9B
map_control_0f6d9b:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
