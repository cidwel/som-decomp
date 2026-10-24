.setcpu "65816"
.segment "CODE"
.org $6338
map_control_0d6338:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
