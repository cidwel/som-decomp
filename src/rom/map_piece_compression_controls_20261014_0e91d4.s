.setcpu "65816"
.segment "CODE"
.org $91D4
map_control_0e91d4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
