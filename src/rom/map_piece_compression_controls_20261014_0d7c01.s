.setcpu "65816"
.segment "CODE"
.org $7C01
map_control_0d7c01:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
