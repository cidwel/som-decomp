.setcpu "65816"
.segment "CODE"
.org $9A9A
map_control_0e9a9a:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
