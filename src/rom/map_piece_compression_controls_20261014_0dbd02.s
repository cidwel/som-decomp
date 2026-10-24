.setcpu "65816"
.segment "CODE"
.org $BD02
map_control_0dbd02:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
