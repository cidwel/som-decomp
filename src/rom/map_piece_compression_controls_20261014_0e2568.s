.setcpu "65816"
.segment "CODE"
.org $2568
map_control_0e2568:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
