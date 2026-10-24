.setcpu "65816"
.segment "CODE"
.org $BBBF
map_control_0dbbbf:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
