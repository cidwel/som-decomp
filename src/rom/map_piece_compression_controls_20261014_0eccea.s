.setcpu "65816"
.segment "CODE"
.org $CCEA
map_control_0eccea:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
