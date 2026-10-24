.setcpu "65816"
.segment "CODE"
.org $EFDB
map_control_0defdb:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
