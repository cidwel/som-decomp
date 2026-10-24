.setcpu "65816"
.segment "CODE"
.org $0204
map_control_0f0204:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
