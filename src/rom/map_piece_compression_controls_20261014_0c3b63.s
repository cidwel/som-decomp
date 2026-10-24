.setcpu "65816"
.segment "CODE"
.org $3B63
map_control_0c3b63:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
