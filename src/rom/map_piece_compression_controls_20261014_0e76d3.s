.setcpu "65816"
.segment "CODE"
.org $76D3
map_control_0e76d3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
