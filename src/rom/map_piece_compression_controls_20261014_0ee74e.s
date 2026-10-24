.setcpu "65816"
.segment "CODE"
.org $E74E
map_control_0ee74e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
