.setcpu "65816"
.segment "CODE"
.org $39C7
map_control_0e39c7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
