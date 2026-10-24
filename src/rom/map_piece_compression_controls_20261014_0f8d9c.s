.setcpu "65816"
.segment "CODE"
.org $8D9C
map_control_0f8d9c:
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
