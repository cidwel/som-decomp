.setcpu "65816"
.segment "CODE"
.org $CE27
map_control_0ece27:
    .byte $E0 ; previous-row copy escape
    .byte $C1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
