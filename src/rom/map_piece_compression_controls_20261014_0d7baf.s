.setcpu "65816"
.segment "CODE"
.org $7BAF
map_control_0d7baf:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
