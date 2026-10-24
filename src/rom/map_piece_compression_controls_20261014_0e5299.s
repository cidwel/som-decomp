.setcpu "65816"
.segment "CODE"
.org $5299
map_control_0e5299:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
