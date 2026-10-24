.setcpu "65816"
.segment "CODE"
.org $AC4E
map_control_0dac4e:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
