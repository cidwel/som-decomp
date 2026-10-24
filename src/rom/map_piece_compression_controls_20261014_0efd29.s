.setcpu "65816"
.segment "CODE"
.org $FD29
map_control_0efd29:
    .byte $F4 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $F4 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
