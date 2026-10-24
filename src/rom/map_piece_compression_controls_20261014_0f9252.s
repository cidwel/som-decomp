.setcpu "65816"
.segment "CODE"
.org $9252
map_control_0f9252:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
