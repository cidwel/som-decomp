.setcpu "65816"
.segment "CODE"
.org $8DBE
map_control_0d8dbe:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
