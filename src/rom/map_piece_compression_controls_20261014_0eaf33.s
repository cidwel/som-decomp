.setcpu "65816"
.segment "CODE"
.org $AF33
map_control_0eaf33:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
