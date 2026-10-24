.setcpu "65816"
.segment "CODE"
.org $145C
map_control_0f145c:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
