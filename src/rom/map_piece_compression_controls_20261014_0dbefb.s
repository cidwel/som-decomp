.setcpu "65816"
.segment "CODE"
.org $BEFB
map_control_0dbefb:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
