.setcpu "65816"
.segment "CODE"
.org $DDC0
map_control_0fddc0:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
