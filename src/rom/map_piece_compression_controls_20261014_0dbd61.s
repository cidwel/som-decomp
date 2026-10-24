.setcpu "65816"
.segment "CODE"
.org $BD61
map_control_0dbd61:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
