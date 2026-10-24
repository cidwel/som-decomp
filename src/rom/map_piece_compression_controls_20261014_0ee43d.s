.setcpu "65816"
.segment "CODE"
.org $E43D
map_control_0ee43d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
