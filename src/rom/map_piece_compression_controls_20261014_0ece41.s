.setcpu "65816"
.segment "CODE"
.org $CE41
map_control_0ece41:
    .byte $E0 ; previous-row copy escape
    .byte $C3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
