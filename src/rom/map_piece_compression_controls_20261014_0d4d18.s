.setcpu "65816"
.segment "CODE"
.org $4D18
map_control_0d4d18:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
