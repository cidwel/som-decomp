.setcpu "65816"
.segment "CODE"
.org $6C76
map_control_0c6c76:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
