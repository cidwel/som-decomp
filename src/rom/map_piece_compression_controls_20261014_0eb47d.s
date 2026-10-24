.setcpu "65816"
.segment "CODE"
.org $B47D
map_control_0eb47d:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
