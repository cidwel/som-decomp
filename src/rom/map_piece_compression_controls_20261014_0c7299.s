.setcpu "65816"
.segment "CODE"
.org $7299
map_control_0c7299:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
