.setcpu "65816"
.segment "CODE"
.org $0F45
map_control_0f0f45:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
