.setcpu "65816"
.segment "CODE"
.org $416D
map_control_0f416d:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
