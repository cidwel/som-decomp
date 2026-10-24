.setcpu "65816"
.segment "CODE"
.org $BFAB
map_control_0dbfab:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
