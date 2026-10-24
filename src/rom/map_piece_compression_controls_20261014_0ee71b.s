.setcpu "65816"
.segment "CODE"
.org $E71B
map_control_0ee71b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
