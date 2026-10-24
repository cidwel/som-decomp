.setcpu "65816"
.segment "CODE"
.org $CE3A
map_control_0ece3a:
    .byte $E0 ; previous-row copy escape
    .byte $C3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
