.setcpu "65816"
.segment "CODE"
.org $9AF3
map_control_0e9af3:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
