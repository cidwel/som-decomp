.setcpu "65816"
.segment "CODE"
.org $9198
map_control_0d9198:
    .byte $E0 ; previous-row copy escape
    .byte $49 ; row-distance/count
