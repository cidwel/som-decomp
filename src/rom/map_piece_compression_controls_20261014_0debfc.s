.setcpu "65816"
.segment "CODE"
.org $EBFC
map_control_0debfc:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
