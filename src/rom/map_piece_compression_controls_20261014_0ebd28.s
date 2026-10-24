.setcpu "65816"
.segment "CODE"
.org $BD28
map_control_0ebd28:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
