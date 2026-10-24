.setcpu "65816"
.segment "CODE"
.org $2BF8
map_control_0d2bf8:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
