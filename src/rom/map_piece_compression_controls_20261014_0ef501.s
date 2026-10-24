.setcpu "65816"
.segment "CODE"
.org $F501
map_control_0ef501:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
