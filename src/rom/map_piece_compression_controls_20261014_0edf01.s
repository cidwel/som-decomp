.setcpu "65816"
.segment "CODE"
.org $DF01
map_control_0edf01:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
