.setcpu "65816"
.segment "CODE"
.org $13C8
map_control_0e13c8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
