.setcpu "65816"
.segment "CODE"
.org $49CE
map_control_0f49ce:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
