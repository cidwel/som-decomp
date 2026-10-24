.setcpu "65816"
.segment "CODE"
.org $867C
map_control_0d867c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
