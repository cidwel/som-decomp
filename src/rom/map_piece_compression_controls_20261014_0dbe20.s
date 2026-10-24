.setcpu "65816"
.segment "CODE"
.org $BE20
map_control_0dbe20:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
