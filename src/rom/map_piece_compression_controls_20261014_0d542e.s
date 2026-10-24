.setcpu "65816"
.segment "CODE"
.org $542E
map_control_0d542e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
