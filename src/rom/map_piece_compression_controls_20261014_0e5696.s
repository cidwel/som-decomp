.setcpu "65816"
.segment "CODE"
.org $5696
map_control_0e5696:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
