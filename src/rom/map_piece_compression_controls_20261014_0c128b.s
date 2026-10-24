.setcpu "65816"
.segment "CODE"
.org $128B
map_control_0c128b:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
