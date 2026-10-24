.setcpu "65816"
.segment "CODE"
.org $87E9
map_control_0d87e9:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
