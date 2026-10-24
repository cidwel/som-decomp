.setcpu "65816"
.segment "CODE"
.org $70F0
map_control_0c70f0:
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
