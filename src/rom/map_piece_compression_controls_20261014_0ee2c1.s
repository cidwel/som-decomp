.setcpu "65816"
.segment "CODE"
.org $E2C1
map_control_0ee2c1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
