.setcpu "65816"
.segment "CODE"
.org $73CB
map_control_0c73cb:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
