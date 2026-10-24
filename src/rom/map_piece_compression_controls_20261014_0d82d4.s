.setcpu "65816"
.segment "CODE"
.org $82D4
map_control_0d82d4:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
