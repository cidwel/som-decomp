.setcpu "65816"
.segment "CODE"
.org $5984
map_control_0f5984:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
