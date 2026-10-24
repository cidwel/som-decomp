.setcpu "65816"
.segment "CODE"
.org $189F
map_control_0c189f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
