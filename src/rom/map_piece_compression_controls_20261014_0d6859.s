.setcpu "65816"
.segment "CODE"
.org $6859
map_control_0d6859:
    .byte $D3 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
