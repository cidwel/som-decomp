.setcpu "65816"
.segment "CODE"
.org $5DEB
map_control_0f5deb:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
