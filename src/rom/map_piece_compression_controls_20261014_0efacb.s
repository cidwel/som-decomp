.setcpu "65816"
.segment "CODE"
.org $FACB
map_control_0efacb:
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
