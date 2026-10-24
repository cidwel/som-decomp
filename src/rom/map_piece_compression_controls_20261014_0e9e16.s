.setcpu "65816"
.segment "CODE"
.org $9E16
map_control_0e9e16:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
