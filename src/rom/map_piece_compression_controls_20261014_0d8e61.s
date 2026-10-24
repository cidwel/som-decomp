.setcpu "65816"
.segment "CODE"
.org $8E61
map_control_0d8e61:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
