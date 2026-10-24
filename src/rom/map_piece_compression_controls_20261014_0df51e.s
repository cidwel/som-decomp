.setcpu "65816"
.segment "CODE"
.org $F51E
map_control_0df51e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
