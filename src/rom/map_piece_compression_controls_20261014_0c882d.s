.setcpu "65816"
.segment "CODE"
.org $882D
map_control_0c882d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
