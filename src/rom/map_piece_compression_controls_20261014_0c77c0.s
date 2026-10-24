.setcpu "65816"
.segment "CODE"
.org $77C0
map_control_0c77c0:
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
