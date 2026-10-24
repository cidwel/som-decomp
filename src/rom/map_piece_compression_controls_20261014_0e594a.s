.setcpu "65816"
.segment "CODE"
.org $594A
map_control_0e594a:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $F1 ; progressive-copy count
