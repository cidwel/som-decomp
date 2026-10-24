.setcpu "65816"
.segment "CODE"
.org $91C7
map_control_0e91c7:
    .byte $F2 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
