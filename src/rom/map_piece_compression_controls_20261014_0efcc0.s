.setcpu "65816"
.segment "CODE"
.org $FCC0
map_control_0efcc0:
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
