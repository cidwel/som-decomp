.setcpu "65816"
.segment "CODE"
.org $0C73
map_control_0d0c73:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
