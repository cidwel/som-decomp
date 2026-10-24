.setcpu "65816"
.segment "CODE"
.org $319F
map_control_0e319f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
