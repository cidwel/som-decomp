.setcpu "65816"
.segment "CODE"
.org $7C2E
map_control_0c7c2e:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
