.setcpu "65816"
.segment "CODE"
.org $C41C
map_control_0ec41c:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
