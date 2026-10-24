.setcpu "65816"
.segment "CODE"
.org $BA2C
map_control_0dba2c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
