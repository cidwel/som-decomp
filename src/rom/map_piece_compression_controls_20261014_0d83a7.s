.setcpu "65816"
.segment "CODE"
.org $83A7
map_control_0d83a7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
