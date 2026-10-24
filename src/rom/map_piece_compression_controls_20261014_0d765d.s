.setcpu "65816"
.segment "CODE"
.org $765D
map_control_0d765d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
