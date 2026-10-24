.setcpu "65816"
.segment "CODE"
.org $9F95
map_control_0e9f95:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
