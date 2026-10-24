.setcpu "65816"
.segment "CODE"
.org $0DA2
map_control_0f0da2:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
