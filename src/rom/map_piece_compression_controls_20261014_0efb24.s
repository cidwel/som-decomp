.setcpu "65816"
.segment "CODE"
.org $FB24
map_control_0efb24:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
