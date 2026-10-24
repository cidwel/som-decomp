.setcpu "65816"
.segment "CODE"
.org $EDFE
map_control_0dedfe:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
