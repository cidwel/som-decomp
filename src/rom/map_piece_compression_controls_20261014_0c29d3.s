.setcpu "65816"
.segment "CODE"
.org $29D3
map_control_0c29d3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
