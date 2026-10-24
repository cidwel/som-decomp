.setcpu "65816"
.segment "CODE"
.org $7B32
map_control_0d7b32:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
