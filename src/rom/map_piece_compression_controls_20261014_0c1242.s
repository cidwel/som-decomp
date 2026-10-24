.setcpu "65816"
.segment "CODE"
.org $1242
map_control_0c1242:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
