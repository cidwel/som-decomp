.setcpu "65816"
.segment "CODE"
.org $76EF
map_control_0d76ef:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
