.setcpu "65816"
.segment "CODE"
.org $23C7
map_control_0e23c7:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
