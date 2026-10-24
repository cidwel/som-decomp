.setcpu "65816"
.segment "CODE"
.org $FBEF
map_control_0ffbef:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
