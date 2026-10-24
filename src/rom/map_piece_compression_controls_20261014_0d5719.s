.setcpu "65816"
.segment "CODE"
.org $5719
map_control_0d5719:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
