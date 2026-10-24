.setcpu "65816"
.segment "CODE"
.org $5010
map_control_0f5010:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $C7 ; same-value copy count/distance
