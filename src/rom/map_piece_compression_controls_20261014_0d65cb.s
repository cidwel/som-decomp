.setcpu "65816"
.segment "CODE"
.org $65CB
map_control_0d65cb:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
