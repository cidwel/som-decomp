.setcpu "65816"
.segment "CODE"
.org $7DEB
map_control_0c7deb:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
