.setcpu "65816"
.segment "CODE"
.org $A971
map_control_0da971:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
