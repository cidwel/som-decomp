.setcpu "65816"
.segment "CODE"
.org $A277
map_control_0da277:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
