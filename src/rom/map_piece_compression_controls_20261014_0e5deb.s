.setcpu "65816"
.segment "CODE"
.org $5DEB
map_control_0e5deb:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
