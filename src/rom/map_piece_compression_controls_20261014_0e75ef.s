.setcpu "65816"
.segment "CODE"
.org $75EF
map_control_0e75ef:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
