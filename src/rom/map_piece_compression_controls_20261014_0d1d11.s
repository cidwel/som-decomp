.setcpu "65816"
.segment "CODE"
.org $1D11
map_control_0d1d11:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
