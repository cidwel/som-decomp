.setcpu "65816"
.segment "CODE"
.org $7C89
map_control_0e7c89:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
