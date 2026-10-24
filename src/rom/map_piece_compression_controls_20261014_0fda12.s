.setcpu "65816"
.segment "CODE"
.org $DA12
map_control_0fda12:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
