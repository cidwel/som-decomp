.setcpu "65816"
.segment "CODE"
.org $CDEC
map_control_0dcdec:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
