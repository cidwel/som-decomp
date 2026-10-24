.setcpu "65816"
.segment "CODE"
.org $CDDB
map_control_0dcddb:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
