.setcpu "65816"
.segment "CODE"
.org $2669
map_control_0c2669:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
