.setcpu "65816"
.segment "CODE"
.org $95E8
map_control_0e95e8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
