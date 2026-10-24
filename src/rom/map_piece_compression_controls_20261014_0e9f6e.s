.setcpu "65816"
.segment "CODE"
.org $9F6E
map_control_0e9f6e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
