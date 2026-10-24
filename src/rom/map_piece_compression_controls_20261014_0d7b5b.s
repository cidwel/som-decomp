.setcpu "65816"
.segment "CODE"
.org $7B5B
map_control_0d7b5b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
