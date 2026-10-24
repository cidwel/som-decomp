.setcpu "65816"
.segment "CODE"
.org $75D8
map_control_0c75d8:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
