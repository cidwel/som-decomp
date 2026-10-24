.setcpu "65816"
.segment "CODE"
.org $81D8
map_control_0d81d8:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
