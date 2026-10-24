.setcpu "65816"
.segment "CODE"
.org $BE06
map_control_0ebe06:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
