.setcpu "65816"
.segment "CODE"
.org $16CD
map_control_0c16cd:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
