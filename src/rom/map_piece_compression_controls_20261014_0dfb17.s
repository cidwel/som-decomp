.setcpu "65816"
.segment "CODE"
.org $FB17
map_control_0dfb17:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
