.setcpu "65816"
.segment "CODE"
.org $AABF
map_control_0eaabf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
