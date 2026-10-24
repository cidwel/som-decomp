.setcpu "65816"
.segment "CODE"
.org $BB67
map_control_0dbb67:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
