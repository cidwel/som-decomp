.setcpu "65816"
.segment "CODE"
.org $BC07
map_control_0ebc07:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
