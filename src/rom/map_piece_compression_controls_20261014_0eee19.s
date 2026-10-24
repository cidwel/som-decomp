.setcpu "65816"
.segment "CODE"
.org $EE19
map_control_0eee19:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
