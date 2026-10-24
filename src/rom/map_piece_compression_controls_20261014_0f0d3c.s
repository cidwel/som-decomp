.setcpu "65816"
.segment "CODE"
.org $0D3C
map_control_0f0d3c:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
