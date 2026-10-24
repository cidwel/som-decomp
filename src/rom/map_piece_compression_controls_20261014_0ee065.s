.setcpu "65816"
.segment "CODE"
.org $E065
map_control_0ee065:
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
