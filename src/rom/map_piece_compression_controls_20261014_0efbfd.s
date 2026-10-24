.setcpu "65816"
.segment "CODE"
.org $FBFD
map_control_0efbfd:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
