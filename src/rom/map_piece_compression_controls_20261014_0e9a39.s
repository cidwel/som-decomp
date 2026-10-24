.setcpu "65816"
.segment "CODE"
.org $9A39
map_control_0e9a39:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
