.setcpu "65816"
.segment "CODE"
.org $E1EA
map_control_0ee1ea:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
