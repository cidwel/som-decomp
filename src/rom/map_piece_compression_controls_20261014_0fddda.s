.setcpu "65816"
.segment "CODE"
.org $DDDA
map_control_0fddda:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
