.setcpu "65816"
.segment "CODE"
.org $210D
map_control_0f210d:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
