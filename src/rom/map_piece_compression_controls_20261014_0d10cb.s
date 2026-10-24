.setcpu "65816"
.segment "CODE"
.org $10CB
map_control_0d10cb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
