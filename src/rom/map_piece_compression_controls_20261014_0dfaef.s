.setcpu "65816"
.segment "CODE"
.org $FAEF
map_control_0dfaef:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
