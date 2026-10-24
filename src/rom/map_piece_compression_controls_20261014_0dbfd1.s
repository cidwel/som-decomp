.setcpu "65816"
.segment "CODE"
.org $BFD1
map_control_0dbfd1:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
