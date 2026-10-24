.setcpu "65816"
.segment "CODE"
.org $F6EB
map_control_0df6eb:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $65 ; row-distance/count
