.setcpu "65816"
.segment "CODE"
.org $6D8E
map_control_0c6d8e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
