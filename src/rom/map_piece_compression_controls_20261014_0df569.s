.setcpu "65816"
.segment "CODE"
.org $F569
map_control_0df569:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
