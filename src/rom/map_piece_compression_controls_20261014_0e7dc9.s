.setcpu "65816"
.segment "CODE"
.org $7DC9
map_control_0e7dc9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
