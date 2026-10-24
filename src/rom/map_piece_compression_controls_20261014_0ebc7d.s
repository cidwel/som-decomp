.setcpu "65816"
.segment "CODE"
.org $BC7D
map_control_0ebc7d:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
