.setcpu "65816"
.segment "CODE"
.org $C144
map_control_0ec144:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
