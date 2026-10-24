.setcpu "65816"
.segment "CODE"
.org $9B5E
map_control_0e9b5e:
    .byte $E0 ; previous-row copy escape
    .byte $BD ; row-distance/count
