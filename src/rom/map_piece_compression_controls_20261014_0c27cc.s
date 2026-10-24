.setcpu "65816"
.segment "CODE"
.org $27CC
map_control_0c27cc:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
