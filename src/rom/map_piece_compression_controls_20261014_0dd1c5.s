.setcpu "65816"
.segment "CODE"
.org $D1C5
map_control_0dd1c5:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
