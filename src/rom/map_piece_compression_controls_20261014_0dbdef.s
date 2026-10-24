.setcpu "65816"
.segment "CODE"
.org $BDEF
map_control_0dbdef:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
