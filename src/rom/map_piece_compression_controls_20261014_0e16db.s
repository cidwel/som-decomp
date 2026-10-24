.setcpu "65816"
.segment "CODE"
.org $16DB
map_control_0e16db:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
