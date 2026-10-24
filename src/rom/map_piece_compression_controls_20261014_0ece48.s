.setcpu "65816"
.segment "CODE"
.org $CE48
map_control_0ece48:
    .byte $E0 ; previous-row copy escape
    .byte $C3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
