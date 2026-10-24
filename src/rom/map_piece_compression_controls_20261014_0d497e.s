.setcpu "65816"
.segment "CODE"
.org $497E
map_control_0d497e:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
