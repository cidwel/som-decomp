.setcpu "65816"
.segment "CODE"
.org $9E52
map_control_0e9e52:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
