.setcpu "65816"
.segment "CODE"
.org $545A
map_control_0f545a:
    .byte $F1 ; progressive-copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
