.setcpu "65816"
.segment "CODE"
.org $F0D5
map_control_0cf0d5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
