.setcpu "65816"
.segment "CODE"
.org $D9C2
map_control_0fd9c2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
