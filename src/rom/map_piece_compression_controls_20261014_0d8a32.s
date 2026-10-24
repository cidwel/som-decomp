.setcpu "65816"
.segment "CODE"
.org $8A32
map_control_0d8a32:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
