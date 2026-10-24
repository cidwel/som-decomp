.setcpu "65816"
.segment "CODE"
.org $70AE
map_control_0c70ae:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
