.setcpu "65816"
.segment "CODE"
.org $BB35
map_control_0dbb35:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
