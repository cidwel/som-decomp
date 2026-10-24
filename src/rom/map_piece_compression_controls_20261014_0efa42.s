.setcpu "65816"
.segment "CODE"
.org $FA42
map_control_0efa42:
    .byte $E0 ; previous-row copy escape
    .byte $BD ; row-distance/count
