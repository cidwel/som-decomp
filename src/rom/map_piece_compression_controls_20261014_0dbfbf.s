.setcpu "65816"
.segment "CODE"
.org $BFBF
map_control_0dbfbf:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
