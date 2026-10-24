.setcpu "65816"
.segment "CODE"
.org $F4CE
map_control_0df4ce:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
