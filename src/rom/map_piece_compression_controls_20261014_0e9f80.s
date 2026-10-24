.setcpu "65816"
.segment "CODE"
.org $9F80
map_control_0e9f80:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
