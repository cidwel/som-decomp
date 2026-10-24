.setcpu "65816"
.segment "CODE"
.org $7CCD
map_control_0d7ccd:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
