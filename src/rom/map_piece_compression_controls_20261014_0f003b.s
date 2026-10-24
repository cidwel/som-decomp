.setcpu "65816"
.segment "CODE"
.org $003B
map_control_0f003b:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
