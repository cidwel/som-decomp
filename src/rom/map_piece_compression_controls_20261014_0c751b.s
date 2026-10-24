.setcpu "65816"
.segment "CODE"
.org $751B
map_control_0c751b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
