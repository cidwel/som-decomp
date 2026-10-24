.setcpu "65816"
.segment "CODE"
.org $8C02
map_control_0f8c02:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
