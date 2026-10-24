.setcpu "65816"
.segment "CODE"
.org $FBCD
map_control_0ffbcd:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
