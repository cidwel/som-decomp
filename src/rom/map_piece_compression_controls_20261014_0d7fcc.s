.setcpu "65816"
.segment "CODE"
.org $7FCC
map_control_0d7fcc:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
