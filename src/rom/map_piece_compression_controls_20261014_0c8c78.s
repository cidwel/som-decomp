.setcpu "65816"
.segment "CODE"
.org $8C78
map_control_0c8c78:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
