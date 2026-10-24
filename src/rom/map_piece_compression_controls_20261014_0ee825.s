.setcpu "65816"
.segment "CODE"
.org $E825
map_control_0ee825:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
