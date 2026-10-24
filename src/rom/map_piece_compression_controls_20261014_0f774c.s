.setcpu "65816"
.segment "CODE"
.org $774C
map_control_0f774c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
