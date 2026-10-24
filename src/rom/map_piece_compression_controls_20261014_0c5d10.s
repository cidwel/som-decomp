.setcpu "65816"
.segment "CODE"
.org $5D10
map_control_0c5d10:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
