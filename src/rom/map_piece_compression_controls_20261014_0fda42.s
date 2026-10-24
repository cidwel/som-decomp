.setcpu "65816"
.segment "CODE"
.org $DA42
map_control_0fda42:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
