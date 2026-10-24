.setcpu "65816"
.segment "CODE"
.org $81D4
map_control_0d81d4:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
