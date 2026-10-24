.setcpu "65816"
.segment "CODE"
.org $A68B
map_control_0da68b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
