.setcpu "65816"
.segment "CODE"
.org $749B
map_control_0e749b:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
