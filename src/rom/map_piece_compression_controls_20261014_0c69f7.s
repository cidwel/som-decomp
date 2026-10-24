.setcpu "65816"
.segment "CODE"
.org $69F7
map_control_0c69f7:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
