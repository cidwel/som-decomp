.setcpu "65816"
.segment "CODE"
.org $CB17
map_control_0dcb17:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
