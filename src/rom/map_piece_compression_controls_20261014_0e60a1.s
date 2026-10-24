.setcpu "65816"
.segment "CODE"
.org $60A1
map_control_0e60a1:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
