.setcpu "65816"
.segment "CODE"
.org $E277
map_control_0ee277:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
