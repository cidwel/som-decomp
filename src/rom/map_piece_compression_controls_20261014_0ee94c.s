.setcpu "65816"
.segment "CODE"
.org $E94C
map_control_0ee94c:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
