.setcpu "65816"
.segment "CODE"
.org $17D3
map_control_0e17d3:
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
