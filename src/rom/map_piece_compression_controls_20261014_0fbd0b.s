.setcpu "65816"
.segment "CODE"
.org $BD0B
map_control_0fbd0b:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
