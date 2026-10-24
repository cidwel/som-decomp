.setcpu "65816"
.segment "CODE"
.org $31D3
map_control_0c31d3:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
