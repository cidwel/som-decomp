.setcpu "65816"
.segment "CODE"
.org $9D3E
map_control_0d9d3e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
    .byte $C6 ; same-value copy count/distance
