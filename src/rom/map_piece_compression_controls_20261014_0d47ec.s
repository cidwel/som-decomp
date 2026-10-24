.setcpu "65816"
.segment "CODE"
.org $47EC
map_control_0d47ec:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
