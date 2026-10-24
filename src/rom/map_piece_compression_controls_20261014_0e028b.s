.setcpu "65816"
.segment "CODE"
.org $028B
map_control_0e028b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
