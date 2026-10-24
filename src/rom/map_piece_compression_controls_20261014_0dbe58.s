.setcpu "65816"
.segment "CODE"
.org $BE58
map_control_0dbe58:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $F3 ; progressive-copy count
