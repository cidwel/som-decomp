.setcpu "65816"
.segment "CODE"
.org $74C2
map_control_0f74c2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
