.setcpu "65816"
.segment "CODE"
.org $E187
map_control_0ee187:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
