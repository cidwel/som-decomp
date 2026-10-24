.setcpu "65816"
.segment "CODE"
.org $5C48
map_control_0c5c48:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
