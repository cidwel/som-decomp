.setcpu "65816"
.segment "CODE"
.org $11F1
map_control_0c11f1:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
