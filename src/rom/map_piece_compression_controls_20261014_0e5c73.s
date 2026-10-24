.setcpu "65816"
.segment "CODE"
.org $5C73
map_control_0e5c73:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
