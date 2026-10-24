.setcpu "65816"
.segment "CODE"
.org $E703
map_control_0fe703:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
