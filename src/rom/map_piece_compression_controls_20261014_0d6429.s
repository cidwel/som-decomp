.setcpu "65816"
.segment "CODE"
.org $6429
map_control_0d6429:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
