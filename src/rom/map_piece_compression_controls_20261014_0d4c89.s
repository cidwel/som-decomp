.setcpu "65816"
.segment "CODE"
.org $4C89
map_control_0d4c89:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
