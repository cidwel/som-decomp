.setcpu "65816"
.segment "CODE"
.org $E309
map_control_0de309:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
