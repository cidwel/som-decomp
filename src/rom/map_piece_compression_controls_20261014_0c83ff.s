.setcpu "65816"
.segment "CODE"
.org $83FF
map_control_0c83ff:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
