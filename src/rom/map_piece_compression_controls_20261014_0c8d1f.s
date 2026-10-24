.setcpu "65816"
.segment "CODE"
.org $8D1F
map_control_0c8d1f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
