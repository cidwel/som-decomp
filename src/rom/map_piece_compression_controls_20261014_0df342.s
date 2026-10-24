.setcpu "65816"
.segment "CODE"
.org $F342
map_control_0df342:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
