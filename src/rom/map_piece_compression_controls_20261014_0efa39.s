.setcpu "65816"
.segment "CODE"
.org $FA39
map_control_0efa39:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
