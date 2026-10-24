.setcpu "65816"
.segment "CODE"
.org $C3F5
map_control_0dc3f5:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
