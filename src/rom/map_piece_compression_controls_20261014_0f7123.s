.setcpu "65816"
.segment "CODE"
.org $7123
map_control_0f7123:
    .byte $DC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
