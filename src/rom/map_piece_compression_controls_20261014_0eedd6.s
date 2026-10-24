.setcpu "65816"
.segment "CODE"
.org $EDD6
map_control_0eedd6:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
