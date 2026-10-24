.setcpu "65816"
.segment "CODE"
.org $1B40
map_control_0f1b40:
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
