.setcpu "65816"
.segment "CODE"
.org $FFCE
map_control_0effce:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
