.setcpu "65816"
.segment "CODE"
.org $47A5
map_control_0f47a5:
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
