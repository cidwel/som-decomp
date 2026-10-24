.setcpu "65816"
.segment "CODE"
.org $4669
map_control_0c4669:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
