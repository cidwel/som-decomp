.setcpu "65816"
.segment "CODE"
.org $32B6
map_control_0d32b6:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
