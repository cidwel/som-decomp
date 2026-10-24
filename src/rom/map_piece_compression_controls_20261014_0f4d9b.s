.setcpu "65816"
.segment "CODE"
.org $4D9B
map_control_0f4d9b:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $73 ; row-distance/count
