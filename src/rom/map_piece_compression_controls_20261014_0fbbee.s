.setcpu "65816"
.segment "CODE"
.org $BBEE
map_control_0fbbee:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
