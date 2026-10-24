.setcpu "65816"
.segment "CODE"
.org $C059
map_control_0dc059:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $F2 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
