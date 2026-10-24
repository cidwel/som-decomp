.setcpu "65816"
.segment "CODE"
.org $7B01
map_control_0e7b01:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
