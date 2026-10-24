.setcpu "65816"
.segment "CODE"
.org $18FC
map_control_0f18fc:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
