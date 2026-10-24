.setcpu "65816"
.segment "CODE"
.org $22EB
map_control_0d22eb:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
