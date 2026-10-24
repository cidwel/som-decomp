.setcpu "65816"
.segment "CODE"
.org $57CB
map_control_0e57cb:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
