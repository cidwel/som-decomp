.setcpu "65816"
.segment "CODE"
.org $544B
map_control_0d544b:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
