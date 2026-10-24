.setcpu "65816"
.segment "CODE"
.org $47BD
map_control_0f47bd:
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
