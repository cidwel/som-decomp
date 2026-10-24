.setcpu "65816"
.segment "CODE"
.org $BE5D
map_control_0ebe5d:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
