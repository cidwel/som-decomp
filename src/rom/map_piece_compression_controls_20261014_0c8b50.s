.setcpu "65816"
.segment "CODE"
.org $8B50
map_control_0c8b50:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
