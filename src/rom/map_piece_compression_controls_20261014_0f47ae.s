.setcpu "65816"
.segment "CODE"
.org $47AE
map_control_0f47ae:
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
