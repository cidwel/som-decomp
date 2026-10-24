.setcpu "65816"
.segment "CODE"
.org $6BF0
map_control_0d6bf0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
