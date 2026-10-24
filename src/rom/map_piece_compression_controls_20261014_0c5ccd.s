.setcpu "65816"
.segment "CODE"
.org $5CCD
map_control_0c5ccd:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
