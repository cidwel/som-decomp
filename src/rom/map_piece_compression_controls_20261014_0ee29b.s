.setcpu "65816"
.segment "CODE"
.org $E29B
map_control_0ee29b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
