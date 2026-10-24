.setcpu "65816"
.segment "CODE"
.org $7B9A
map_control_0d7b9a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
