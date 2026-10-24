.setcpu "65816"
.segment "CODE"
.org $B81F
map_control_0fb81f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
