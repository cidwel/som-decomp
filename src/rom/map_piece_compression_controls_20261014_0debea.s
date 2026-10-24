.setcpu "65816"
.segment "CODE"
.org $EBEA
map_control_0debea:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
