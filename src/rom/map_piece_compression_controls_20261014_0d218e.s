.setcpu "65816"
.segment "CODE"
.org $218E
map_control_0d218e:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
