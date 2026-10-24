.setcpu "65816"
.segment "CODE"
.org $CDC9
map_control_0ecdc9:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
