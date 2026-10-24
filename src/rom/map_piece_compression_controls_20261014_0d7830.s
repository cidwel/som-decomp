.setcpu "65816"
.segment "CODE"
.org $7830
map_control_0d7830:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
