.setcpu "65816"
.segment "CODE"
.org $BB2E
map_control_0fbb2e:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
