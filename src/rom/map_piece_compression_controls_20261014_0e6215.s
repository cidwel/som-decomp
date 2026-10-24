.setcpu "65816"
.segment "CODE"
.org $6215
map_control_0e6215:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
