.setcpu "65816"
.segment "CODE"
.org $713D
map_control_0c713d:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
