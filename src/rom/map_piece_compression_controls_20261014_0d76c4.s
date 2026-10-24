.setcpu "65816"
.segment "CODE"
.org $76C4
map_control_0d76c4:
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
