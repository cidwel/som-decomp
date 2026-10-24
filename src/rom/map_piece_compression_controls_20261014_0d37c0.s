.setcpu "65816"
.segment "CODE"
.org $37C0
map_control_0d37c0:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
