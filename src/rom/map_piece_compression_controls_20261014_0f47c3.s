.setcpu "65816"
.segment "CODE"
.org $47C3
map_control_0f47c3:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
