.setcpu "65816"
.segment "CODE"
.org $47D9
map_control_0f47d9:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
