.setcpu "65816"
.segment "CODE"
.org $65FF
map_control_0c65ff:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
