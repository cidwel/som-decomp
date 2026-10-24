.setcpu "65816"
.segment "CODE"
.org $2B55
map_control_0d2b55:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
