.setcpu "65816"
.segment "CODE"
.org $5E24
map_control_0c5e24:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
