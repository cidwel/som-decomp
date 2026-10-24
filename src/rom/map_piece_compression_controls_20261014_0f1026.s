.setcpu "65816"
.segment "CODE"
.org $1026
map_control_0f1026:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
