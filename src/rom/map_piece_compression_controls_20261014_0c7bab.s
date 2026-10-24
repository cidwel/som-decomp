.setcpu "65816"
.segment "CODE"
.org $7BAB
map_control_0c7bab:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
