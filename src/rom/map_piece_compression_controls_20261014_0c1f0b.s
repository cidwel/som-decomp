.setcpu "65816"
.segment "CODE"
.org $1F0B
map_control_0c1f0b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
