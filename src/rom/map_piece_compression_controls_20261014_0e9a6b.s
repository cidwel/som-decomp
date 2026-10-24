.setcpu "65816"
.segment "CODE"
.org $9A6B
map_control_0e9a6b:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
