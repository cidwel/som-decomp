.setcpu "65816"
.segment "CODE"
.org $D063
map_control_0dd063:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
