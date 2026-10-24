.setcpu "65816"
.segment "CODE"
.org $69BD
map_control_0e69bd:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
