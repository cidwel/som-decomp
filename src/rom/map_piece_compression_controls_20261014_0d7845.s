.setcpu "65816"
.segment "CODE"
.org $7845
map_control_0d7845:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
