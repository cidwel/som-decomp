.setcpu "65816"
.segment "CODE"
.org $FA6B
map_control_0efa6b:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
