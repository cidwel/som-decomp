.setcpu "65816"
.segment "CODE"
.org $5C49
map_control_0f5c49:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
