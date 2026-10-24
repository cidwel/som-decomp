.setcpu "65816"
.segment "CODE"
.org $FEFA
map_control_0dfefa:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
