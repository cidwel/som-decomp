.setcpu "65816"
.segment "CODE"
.org $B413
map_control_0eb413:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
