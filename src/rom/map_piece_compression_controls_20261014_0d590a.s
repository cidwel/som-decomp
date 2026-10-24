.setcpu "65816"
.segment "CODE"
.org $590A
map_control_0d590a:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
