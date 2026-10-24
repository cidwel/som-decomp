.setcpu "65816"
.segment "CODE"
.org $26CA
map_control_0e26ca:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
