.setcpu "65816"
.segment "CODE"
.org $3B89
map_control_0c3b89:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
