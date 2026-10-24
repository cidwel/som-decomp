.setcpu "65816"
.segment "CODE"
.org $F364
map_control_0df364:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
