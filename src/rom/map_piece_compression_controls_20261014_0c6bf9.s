.setcpu "65816"
.segment "CODE"
.org $6BF9
map_control_0c6bf9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
