.setcpu "65816"
.segment "CODE"
.org $6C93
map_control_0f6c93:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
