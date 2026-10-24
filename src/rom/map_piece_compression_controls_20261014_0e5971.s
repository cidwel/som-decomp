.setcpu "65816"
.segment "CODE"
.org $5971
map_control_0e5971:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
