.setcpu "65816"
.segment "CODE"
.org $8C59
map_control_0f8c59:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
