.setcpu "65816"
.segment "CODE"
.org $717B
map_control_0e717b:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
