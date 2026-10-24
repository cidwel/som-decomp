.setcpu "65816"
.segment "CODE"
.org $7E4F
map_control_0c7e4f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
