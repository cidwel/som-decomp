.setcpu "65816"
.segment "CODE"
.org $32CB
map_control_0e32cb:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
