.setcpu "65816"
.segment "CODE"
.org $3727
map_control_0e3727:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
